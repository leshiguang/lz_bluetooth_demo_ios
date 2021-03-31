//
//  LSViewController.m
//  LSBluetoothUI_iOS
//
//  Created by wm on 09/04/2020.
//  Copyright (c) 2020 wm. All rights reserved.
//

#import "ViewController.h"
#import <Masonry/Masonry.h>
#import <LSBluetoothUI_iOS/LSBluetoothUI.h>

@interface ViewController () <UITableViewDelegate, UITableViewDataSource, LSDeviceManagerDelegate>
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
    /// 需要提供 自己的appkey
    LSBluetoothUIConfig *config = [[LSBluetoothUIConfig alloc] init];
    config.appKey = @"xxx";
    config.appSecret = @"xx";
    config.tn = @"xxx";
    config.debug = YES;
    [LSBluetoothUI initWithConfig:config];
    
    [LSBluetoothUI addDelegate:self];
    
    /// 登陆 associatedId 一般为自己账号系统下的用户id
    [LSBluetoothUI loginWithAssociatedId:@"xxx" completion:^(BOOL result) {
        NSLog(@"登陆是否成功 %@", @(result));
        
        if (result) {
            NSArray *list = [LSBluetoothUI getBoundDevices];
            NSLog(@"list %@", list);
        }
    }];
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
    NSDictionary *dic = self.dataSouceAry[indexPath.row];
    LSPage page = [dic[@"page"] integerValue];
    [LSBluetoothUI openPage:page];
}

#pragma mark - LSDeviceManagerDelegate
- (void)deviceDidReceiveMeasurementDatas:(NSArray<__kindof LSReceiveData *> *)measurementDatas dataType:(LSMeasurementDataType)dataType {
    if (dataType == LSMeasurementDataTypeWeight) {
        NSLog(@"体重数据");
    }
    NSLog(@"receiveData %@", measurementDatas);
}

- (void)device:(LSDevice *)device bindStateChanged:(LSBindStatus)bindState netCode:(NSInteger)netCode netMsg:(NSString *)netMsg {
    if (bindState == LSBindStatusSuccessful) {
        if (device.deviceType == LSDeviceTypePedometer || device.deviceType == LSDeviceTypeBand) {
            LZA5SettingEventRemindData *data = [[LZA5SettingEventRemindData alloc] init];
            /// 事件提醒的索引， 需要开发者自己计算，唯一ID （最多5个提醒）
            data.index = 1;
            data.enable = YES;
            data.hour = 11;
            data.minute = 59;
            data.des = @"喝水";
            data.repeatFlag = LZA5RepeatTimeFlagAll;
            data.vibrationTime = 10;
            data.vibrationType = LZA5VibrationTypeAlways;
            data.vibrationLevel1 = 9;
            data.vibrationLevel2 = 9;
            
            [LSBluetoothUI setSetting:data device:device completion:^(LZBluetoothErrorCode code) {
                NSLog(@"发送结果 %@", @(code));
            }];
            
            double latitude = 31.209086100260418;
            double longitude = 121.40808648003473;
            NSString *adcode = @"310105";
            
            /// 其中adcode 可以通过第三方地图获取，比如阿里地图与百度地图
            [LZBluetooth requestWeatherWithLng:longitude lat:latitude adcode:adcode completion:^(NSInteger code, NSString * _Nonnull msg, LZWeatherData * _Nonnull data) {
                if (data) {
                    [LSBluetoothUI setSetting:data device:device completion:^(LZBluetoothErrorCode code) {
                        NSLog(@"发送结果 %@", @(code));
                    }];
                }
            }];
        }
    }
}

#pragma mark - handler
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
        _dataSouceAry = @[
            @{@"title":@"睡眠", @"page": @(LSPageSleep)},
        @{@"title":@"心率", @"page": @(LSPageHr)},
        @{@"title":@"体重", @"page": @(LSPageWeight)},
        @{@"title":@"步数", @"page": @(LSPageStep)},
        @{@"title":@"血压", @"page": @(LSPageBloodPressure)},
        @{@"title":@"我的设备", @"page": @(LSPageDeviceList)}
        ];
    }
    return _dataSouceAry;
}
@end
