//
//  ViewController.m
//  SDKDemo
//
//  Created by wm on 2020/9/27.
//

#import "ViewController.h"
#import "LZUIViewController.h"

#import <LSDeviceManagerFramework/LSDeviceManager.h>
#import <LSDeviceManagerFramework/LSDeviceManager+Connect.h>
#import <LSDeviceManagerFramework/LSDeviceManager+Bind.h>
#import <LSDeviceManagerFramework/LSDeviceManager+Device.h>
#import <LSDeviceManagerFramework/LSDeviceManager+ScalesSetting.h>
#import <LSBluetoothUI_iOS/LSBluetoothUIManager.h>

#import <LSAuthorization/LSAuthorization.h>


@interface ViewController () <UITableViewDelegate, UITableViewDataSource, LSDeviceComponentDelegate,ScalesReceiveDataDelegate,BloodPressureReceiveDataDelegate,BraceletReceiveDataDelegate>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *dataSouceAry;

@property (nonatomic, strong) LSEDeviceInfo *deviceInfo;
@property (nonatomic, strong) NSString *lzUserId;
@property (nonatomic, strong) NSString *accessToken;
@property (nonatomic, strong) NSString *deviceId;
@property (nonatomic, strong) NSString *macStr;
@property (nonatomic, strong) NSArray *wifiNameAry;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    [self createUI];
    [self initSDK];
}

- (void)createUI {
    self.tableView = [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds style:UITableViewStylePlain];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.tableView.tableFooterView = [UIView new];
    [self.view addSubview:self.tableView];
}

#pragma mark - delegate
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

#pragma mark - Private Methods
- (void)initSDK {
    //开启调试模式
    [[LSDeviceManager shareInstance] openDebug];
    //设置设备代理
    [[LSDeviceManager shareInstance] addDelegate:self];
    [LSDeviceManager shareInstance].scalesDataDelegate = self;
    [LSDeviceManager shareInstance].bloodPressureDataDelegate = self;
    [LSDeviceManager shareInstance].braceletDataDelegate = self;
    //开启数据服务
    [[LSDeviceManager shareInstance] startDataReceiveService];
    __weak typeof(self) weakSelf = self;
    
    [[LSAuthorization sharedInstance] authorizeDevice:@"lx4ec9b2c924ea7283" appSecret:@"4000898b71644b4711695395ac3b3580d86cabaa" associatedId:@"wm123456" callback:^(NSUInteger userId, NSString * _Nonnull accessToken) {
        weakSelf.lzUserId = [NSString stringWithFormat:@"%ld",(long)userId];
        weakSelf.accessToken = accessToken;
        [[LSDeviceManager shareInstance] loginWithUserId:weakSelf.lzUserId];
        
        LSBluetoothUIAccountInfo *accountInfo = [[LSBluetoothUIAccountInfo alloc] init];
        accountInfo.userId = weakSelf.lzUserId;
        accountInfo.accessToken = weakSelf.accessToken;
        [[LSBluetoothUIManager shareInstance] initBluetoothUISDK:accountInfo];
        [self connectDevice];
    }];
}

- (void)connectDevice {
    [[LSDeviceManager shareInstance] getBoundDevices:@([self.lzUserId integerValue]) Completion:^(int code, NSString *msg, NSArray<Device *> *deviceList) {
        if (code != 200) return;
        if (deviceList.count == 0) {
            NSLog(@"---------没有绑定设备");
        }
        for (Device *device in deviceList) {
            [[LSDeviceManager shareInstance] connectDeviceWithDeviceInfo:device];
            if ([device.isActive intValue] == 1) {
                NSLog(@"连接设备-----------%@",device.model);
                [[LSDeviceManager shareInstance] connectDeviceWithDeviceInfo:device];
            }
        }
        
    }];
}


- (void)stopSearchDevice {
    [[LSDeviceManager shareInstance] stopSearchDevice:^(BOOL isStop) {
        if (isStop) {
            NSLog(@"停止搜索");
        }
    }];
}
- (void)requestBindedDevice {
    [[LSDeviceManager shareInstance] getBoundDevices:@([self.lzUserId integerValue]) Completion:^(int code, NSString *msg, NSArray<Device *> *deviceList) {
        if (code != 200) return;
        if (deviceList.count == 0) {
            NSLog(@"---------没有绑定设备pr");
        }
        for (Device *device in deviceList) {
            if ([device.model isEqualToString:@"GBF-2008-BF1"]) {
                NSLog(@"找到目标设备-----------%@",device);
                self.deviceId = device.id;
                self.macStr = device.mac;
                //找到目标设备后重新连接
                [[LSDeviceManager shareInstance] connectDeviceWithDeviceInfo:device];
                break;
            }
        }
        
    }];
}

#pragma mark - event

- (void)HandlerClickCellItem:(NSDictionary *)item {
    if ([item[@"title"] isEqualToString:@"搜索设备"]) {
        [[LSDeviceManager shareInstance] isBleEnableCompletion:^(BOOL isOpenFlags) {
            if (isOpenFlags) {
                LSEProductInfo *productInfo = [[LSEProductInfo alloc] init];
                productInfo.productTypeCode = 3;
                FactoryProducts *facProduct = [[FactoryProducts alloc] init];
                facProduct.bluetoothBroadcastName = @"GBF-2008-BF1";
                facProduct.communicationType = @"4";
                facProduct.model = @"GBF-2008-BF1";
                facProduct.name = @"S30";
                facProduct.productTypeCode = @"02";
                facProduct.randomCode = 0;
                facProduct.transferProtocal = @"InterConnection";
                productInfo.factoryProducts = @[facProduct];
                [[LSDeviceManager shareInstance] searchDevice:productInfo searchBlock:^(LSEDeviceInfo *info, NSInteger rssi) {
                    if ([info.name isEqualToString:@"GBF-2008-BF1"]) {
                        NSLog(@"目标设备 --- %@",info.name);
                        self.deviceInfo = info;
                        [self stopSearchDevice];
                    }
                }];
            }else {
                
            }
        }];
    }
    else if ([item[@"title"] isEqualToString:@"停止搜索"]) {
        [self stopSearchDevice];
    }
    else if ([item[@"title"] isEqualToString:@"绑定设备"]) {
        [[LSDeviceManager shareInstance] pairDevice:self.deviceInfo];
    }
    else if ([item[@"title"] isEqualToString:@"取消绑定"]) {
        LSEDeviceInfo *deviceInfo = [[LSEDeviceInfo alloc] init];
        deviceInfo.mac = self.macStr;
        [[LSDeviceManager shareInstance] cancelPair:deviceInfo completionBlock:^(SettingCode code) {
            if (code == SettingCodeSuccess) {
                //绑定成功
            }
            NSLog(@"解绑结果回调------%lu",(unsigned long)code);
        }];
    }
    else if ([item[@"title"] isEqualToString:@"获取已绑定设备"]) {
        [self requestBindedDevice];
    }
    else if ([item[@"title"] isEqualToString:@"搜索wifi"]) {
        [[LSDeviceManager shareInstance] scanWifiWith:self.deviceId];
    }
    else if ([item[@"title"] isEqualToString:@"连接wifi"]) {
        for (LSScaleWifiModelItem *item in self.wifiNameAry) {
            NSLog(@"wifi ssidName: %@ bssid: %@",item.ssidName,item.bssid);
            if ([item.ssidName isEqual:@"lifesense_2.4G"]) {
                NSLog(@"找到目标wifi----%@",item.ssidName);
                [[LSDeviceManager shareInstance] connectWifi:item.bssid password:@"life8511" deviceId:self.deviceId];
                break;
            }
        }
    }
    else if ([item[@"title"] isEqualToString:@"乐智UI"]) {
        LZUIViewController *uiVC = [[LZUIViewController alloc] init];
        uiVC.accessToken = self.accessToken;
        uiVC.userId = self.lzUserId;
        [self.navigationController pushViewController:uiVC animated:YES];
    }
    
}

#pragma mark - LSDeviceComponentDelegate 绑定结果回调
- (void)onBindStatusChange:(LSEBindStatusCode)bindCode device:(Device *)device deviceUsers:(NSArray<DeviceUser *> *)deviceUsers netCode:(NSInteger)netCode netMsg:(NSString *)netMsg object:(NSObject *)object {
    NSLog(@"bindCode --- %lu",(unsigned long)bindCode);
    if (deviceUsers && bindCode == LSEBindStatusSuccessful) {
        NSLog(@"绑定成功---");
        [[LSDeviceManager shareInstance] startDataReceiveService];
    }
}

- (void)onDeviceConnectStateChange:(BluetoothConnectState)connectState broadcastId:(NSString *)broadcastId {
    NSLog(@"蓝牙连接状态改变----connectState:%ld broadcastId:%@",(long)connectState,broadcastId);
}

#pragma mark - scale Delegate
- (void)onReceiveScalesWeightData:(WeightData *)weightData {
    NSLog(@"获取体重数据------%@",weightData);
}

- (void)onReceiveSaclesSsidName:(LSScaleWifiModel *)wifiMode {
    NSLog(@"获取ssid名称-----%@",wifiMode.wifiModelAry);
    self.wifiNameAry = wifiMode.wifiModelAry;
}

- (void)onReceiveScalesWifiConnectState:(NSInteger *)state {
    NSLog(@"配网结果回调------%ld",(long)state);
}

#pragma mark - BraceletReceiveDataDelegate 回调
- (void)onReceiveBraceletData:(id)data dataType:(BraceletReceiveDataType)type {
    NSString *className = NSStringFromTransactionState(type);
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


#pragma mark - setter getter

- (NSArray *)dataSouceAry {
    if (!_dataSouceAry) {
        _dataSouceAry = @[@{@"title":@"搜索设备"}
                          ,@{@"title":@"停止搜索"}
                          ,@{@"title":@"绑定设备"}
                          ,@{@"title":@"取消绑定"}
                          ,@{@"title":@"获取已绑定设备"}
                          ,@{@"title":@"搜索wifi"}
                          ,@{@"title":@"连接wifi"}
                          ,@{@"title":@"乐智UI"}
      ];    }
    return _dataSouceAry;
}
@end
