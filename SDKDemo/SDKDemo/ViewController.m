//
//  LSViewController.m
//  LSBluetoothUI_iOS
//
//  Created by wm on 09/04/2020.
//  Copyright (c) 2020 wm. All rights reserved.
//

#import "ViewController.h"
#import <Masonry.h>
#import <LSBluetoothUI_iOS/LSBluetoothUIManager.h>
#import <YYModel/YYModel.h>
#import <CoreLocation/CoreLocation.h>
#import <LSDeviceManagerFramework/LSDeviceManager+ScalesSetting.h>
#import <LSDeviceManagerFramework/LSDeviceManager+Connect.h>
#import <LSDeviceManagerFramework/LSDeviceManager.h>
#import <LSDeviceManagerFramework/LSDeviceManager+Device.h>
#import <LSDeviceManagerFramework/LSDeviceManager+Sync.h>
#import <LSDeviceManagerFramework/LSDeviceManager+Bind.h>
#import <LSAuthorization/LSAuthorization.h>

@interface ViewController () <UITableViewDelegate, UITableViewDataSource, BraceletReceiveDataDelegate,ScalesReceiveDataDelegate,BloodPressureReceiveDataDelegate,LSDeviceComponentDelegate>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *dataSouceAry;

@property (nonatomic, strong) NSArray *wifiNameAry;

@property (nonatomic, strong) NSString *lzUserId;
@property (nonatomic, strong) NSString *accessToken;
@property (nonatomic, strong) NSString *deviceId;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"LSBluetoothDemo";
    [self createUI];
    [self initSDK];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}

- (void)createUI {
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.top.bottom.equalTo(self.view);
    }];
}

- (void)initSDK {
    
    [[LSDeviceManager shareInstance] enablePrint:YES enableWriteToFile:YES];
    //设置设备代理
    [[LSDeviceManager shareInstance] addDelegate:self];
    [LSDeviceManager shareInstance].braceletDataDelegate = self;
    [LSDeviceManager shareInstance].scalesDataDelegate = self;
    [LSDeviceManager shareInstance].bloodPressureDataDelegate = self;
    
    __weak typeof(self) weakSelf = self;
    [[LSAuthorization sharedInstance] authorizeDevice:@"lxd81836bc0ffa8084" appSecret:@"d7c3ad483bebe3c99b67b521b96efad0d5d8c4d1" associatedId:@"wm123456ls" callback:^(NSUInteger userId, NSString * _Nonnull accessToken) {
        
        weakSelf.lzUserId = [NSString stringWithFormat:@"%ld",(long)userId];
        weakSelf.accessToken = accessToken;
        [[LSDeviceManager shareInstance] loginWithUserId:weakSelf.lzUserId];
        
        LSBluetoothUIAccountInfo *accountInfo = [[LSBluetoothUIAccountInfo alloc] init];
        accountInfo.userId = weakSelf.lzUserId;
        accountInfo.accessToken = weakSelf.accessToken;
        accountInfo.tenantName = @"dingding";
        [[LSBluetoothUIManager shareInstance] initBluetoothUISDK:accountInfo];
        
        [[LSDeviceManager shareInstance] uploadFile];
    }];
}

- (void)requestProductList {
    NSArray *ary = [[LSDeviceManager shareInstance] getProductInfoListAry];
    NSLog(@"ary ---- %@",ary);
}

#pragma mark - tableView delegate
- (nonnull UITableViewCell *)tableView:(nonnull UITableView *)tableView cellForRowAtIndexPath:(nonnull NSIndexPath *)indexPath {
    UITableViewCell *cell = [[UITableViewCell alloc] init];
    cell.textLabel.text = [NSString stringWithFormat:@"%@",self.dataSouceAry[indexPath.row][@"title"]];
    return cell;
}

- (NSInteger)tableView:(nonnull UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSouceAry.count;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 50;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [self HandlerClickCellItem:self.dataSouceAry[indexPath.row]];
}

#pragma mark - handler

- (void)HandlerClickCellItem:(NSDictionary *)item {
    if ([item[@"title"] isEqualToString:@"同步用户信息"]) {
        LSBluetoothUIUserInfo *userInfo = [[LSBluetoothUIUserInfo alloc] init];
        userInfo.name = @"wm";
        userInfo.sex = @(1);
        userInfo.birthday = @"960284898000";
        userInfo.height = @(170);
        userInfo.id = @([[LSBluetoothUIConfig defaultConfig].accountInfo.userId integerValue]);
        [[LSBluetoothUIManager shareInstance] updateUserInfo:userInfo completion:^(LSBluetoothResultType resultType) {
            if (resultType == LSBluetoothResultTypeSusses) {
                NSLog(@"用户信息更新成功");
            }
        }];
    } else if ([item[@"title"] isEqualToString:@"我的设备"]) {
        [self.navigationController pushViewController:[[LSBluetoothUIManager shareInstance] lsPageBindDeviceList] animated:YES];
    } else if ([item[@"title"] isEqualToString:@"体重"]) {
        [[LSBluetoothUIManager shareInstance] lsOpenWeightPage];
    } else if ([item[@"title"] isEqualToString:@"步数"]) {
        [[LSBluetoothUIManager shareInstance] lsStepPage];
    } else if ([item[@"title"] isEqualToString:@"睡眠"]) {
        [[LSBluetoothUIManager shareInstance] lsSleepRatePage];
    } else if ([item[@"title"] isEqualToString:@"心率"]) {
        [[LSBluetoothUIManager shareInstance] lsHeartRatePage];
    } else if ([item[@"title"] isEqualToString:@"血压"]) {
        [[LSBluetoothUIManager shareInstance] lsBloodpressurePage];
    } else if ([item[@"title"] isEqualToString:@"有氧能力"]) {
        [[LSBluetoothUIManager shareInstance] lsAerobicRatePage];
    } else if ([item[@"title"] isEqualToString:@"获取设备信息"]) {
        [self requestProductList];
    }
}

#pragma mark - LSDeviceComponentDelegate
- (void)onBindStatusChange:(LSEBindStatusCode)bindCode device:(Device *)device deviceUsers:(NSArray<DeviceUser *> *)deviceUsers netCode:(NSInteger)netCode netMsg:(NSString *)netMsg object:(NSObject *)object {
}

- (void)onDeviceConnectStateChange:(BluetoothConnectState)connectState broadcastId:(NSString *)broadcastId {
    NSLog(@"蓝牙连接状态改变----connectState:%ld broadcastId:%@",(long)connectState,broadcastId);
}

- (void)onReceiveTrackMode:(NSString *)deviceId state:(SportStateData *)state {
    NSLog(@"轨迹跑模式回调接口 --- deviceId ------ %@",deviceId);
}

#pragma mark - BloodPressureReceiveDataDelegate
- (void)onReceiveBraceletData:(id)data dataType:(BraceletReceiveDataType)type {
    NSString *className = NSStringFromTransactionState(type);
    NSLog(@"数据回调------%@",data);
    Class cls = NSClassFromString(className);
    if (![data isKindOfClass:cls]) {
        return;
    }
    switch (type) {
        case WalkingDataType: {
            WalkingData *walkingData = [[cls alloc] init];
            walkingData = (WalkingData *)data;
        }
            break;
            
        default:
            break;
    }
}

#pragma mark - ScalesReceiveDataDelegate
- (void)onReceiveScalesWeightData:(WeightData *)weightData {}

- (void)onReceiveSaclesSsidName:(LSScaleWifiModel *)wifiMode {}

- (void)onReceiveScalesWifiConnectState:(NSInteger *)state {}

#pragma mark - BloodPressureReceiveDataDelegate
- (void)onReceiveBloodPressureMeasureData:(LSSphygmometerData *)bloodPressureData {}

#pragma mark - setter getter
- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.tableFooterView = [UIView new];
    }
    return _tableView;
}

- (NSArray *)dataSouceAry {
    if (!_dataSouceAry) {
        _dataSouceAry = @[@{@"title":@"同步用户信息"}
                            ,@{@"title":@"睡眠"}
                            ,@{@"title":@"心率"}
                            ,@{@"title":@"体重"}
                            ,@{@"title":@"步数"}
                            ,@{@"title":@"血压"}
                            ,@{@"title":@"有氧能力"}
                            ,@{@"title":@"我的设备"}
                            ,@{@"title":@"获取设备信息"}
        ];
    }
    return _dataSouceAry;
}
@end
