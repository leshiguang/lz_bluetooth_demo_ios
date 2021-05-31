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
#import <LSBluetoothUI_iOS/UIViewController+MBProgressHUD.h>
@import SDWebImage;

typedef NS_ENUM(NSUInteger, LSTestType) {
    LSTestTypePage,
    LSTestTypeLogin,
    LSTestTypeLogout,
    
};

@interface ViewController () <UITableViewDelegate, UITableViewDataSource, LSDeviceManagerDelegate>

@property (nonatomic, strong) UILabel *userInfoLabel;
@property (nonatomic, strong) UITextField *textField;

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
    
    self.navigationController.navigationBar.barTintColor = [UIColor whiteColor];
}

- (void)createUI {
    [self.view addSubview:self.userInfoLabel];
    [self.view addSubview:self.textField];
    [self.view addSubview:self.tableView];
    
    [self.userInfoLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        if (@available(iOS 11.0, *)) {
            make.top.equalTo(self.view.mas_safeAreaLayoutGuideTop).offset(5);
        } else {
            // Fallback on earlier versions
            make.top.equalTo(self.view).offset(5 + 64);
        }
        make.left.equalTo(self.view.mas_left).offset(15);
        make.right.equalTo(self.view.mas_right).offset(-15);
        make.height.equalTo(@(50));
    }];
    
    [self.textField mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.userInfoLabel.mas_bottom).offset(10);
        make.left.equalTo(self.view.mas_left).offset(15);
        make.right.equalTo(self.view.mas_right).offset(-15);
        make.height.equalTo(@(50));
    }];
    
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.textField.mas_bottom).offset(10);
        make.left.right.bottom.equalTo(self.view);
    }];
}

- (void)initSDK {

    LSBluetoothUIConfig *config = [[LSBluetoothUIConfig alloc] init];
    
    /// 需要申请
    config.appKey = @"xxxx";
    /// 需要申请
    config.appSecret = @"xxxx";
    /// 需要申请
    config.tn = @"xxxx";
    /// 需要申请
    config.appType = @"xxxx";
    
#ifdef DEBUG
    config.debug = YES;
#endif
    
    /// 需要去微信开放平台申请
    config.wxAppid = @"wx2476166986b43ce4";
    /// 需要自己设置 参考微信开放平台
    config.wxUniversalLink = @"https://www.lifesense.com/";
    [LSBluetoothUI initWithConfig:config];
    
    [LSBluetoothUI addDelegate:self];
    
    __weak typeof(self) weakSelf = self;
    
    /// 这个associateId 一般可以使用你们自己平台上的用户id，
    [LSBluetoothUI loginWithAssociatedId:self.textField.text completion:^(BOOL result) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [weakSelf hideActivityIndicatorHUD];
            [[UIApplication sharedApplication].keyWindow endEditing:YES];
            NSString *msg = result ? @"切换成功": @"切换失败";
            [weakSelf showHintMessage:msg duration:1.5];
            weakSelf.userInfoLabel.text = result ? [NSString stringWithFormat:@"当前associatedId:%@", weakSelf.textField.text] : @"未登录";
        });
    }];
    
    
    // 注册桥接口， 自定义处理比如分享相关的桥接口服务
    [LSBluetoothUI registerHandler:LSJBShareWxminiProgramName handler:^(id  _Nullable data, LSJBResponseCallback  _Nonnull responseCallback) {
        NSLog(@"data %@", data);
        responseCallback(@{@"code" : @(0),
                           @"errMessage" : @""});
    }];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [super touchesBegan:touches withEvent:event];
    
    [[UIApplication sharedApplication].keyWindow endEditing:YES];
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
    LSTestType testType = [dic[@"type"] integerValue];
    switch (testType) {
        case LSTestTypePage: {
            LSPage page = [dic[@"page"] integerValue];
            [LSBluetoothUI openPage:page];
            break;
        }
        case LSTestTypeLogin: {
            [self showActivityIndicatorViewWithTitle:@""];
            __weak typeof(self) weakSelf = self;
            
            [LSBluetoothUI loginWithAssociatedId:self.textField.text completion:^(BOOL result) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [weakSelf hideActivityIndicatorHUD];
                    [[UIApplication sharedApplication].keyWindow endEditing:YES];
                    NSString *msg = result ? @"切换成功": @"切换失败";
                    [weakSelf showHintMessage:msg duration:1.5];
                    weakSelf.userInfoLabel.text = result ? [NSString stringWithFormat:@"当前associatedId:%@", weakSelf.textField.text] : @"未登录";
                });
            }];
            break;
        }
        case LSTestTypeLogout: {
            [LSBluetoothUI logout];
            self.userInfoLabel.text = @"未登录";
            break;
        }
    }
    
}

#pragma mark - LSDeviceManagerDelegate
- (void)deviceDidReceiveMeasurementDatas:(NSArray<__kindof LSReceiveData *> *)measurementDatas dataType:(LSMeasurementDataType)dataType {
    if (dataType == LSMeasurementDataTypeWeight) {
        NSLog(@"体重数据");
        WeightData *data = (WeightData *)measurementDatas;
        NSLog(@"%@", data);
    }
    
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

- (UILabel *)userInfoLabel {
    if (!_userInfoLabel) {
        _userInfoLabel = [[UILabel alloc] init];
        _userInfoLabel.text = @"当前未登录";
        _userInfoLabel.numberOfLines = 0;
        _userInfoLabel.font = [UIFont systemFontOfSize:14];
    }
    return _userInfoLabel;
}

- (UITextField *)textField {
    if (!_textField) {
        _textField = [[UITextField alloc] init];
        _textField.borderStyle = UITextBorderStyleRoundedRect;
        _textField.keyboardType = UIKeyboardTypeASCIICapable;
        _textField.placeholder = @"请输入用户的AssociatedId";
        
//        _textField.text = @"tanjian";
    }
    return _textField;
}

- (NSArray *)dataSouceAry {
    if (!_dataSouceAry) {
        _dataSouceAry = @[
            @{@"title":@"切换用户", @"type": @(LSTestTypeLogin)},
            @{@"title":@"睡眠", @"page": @(LSPageSleep), @"type": @(LSTestTypePage)},
            @{@"title":@"心率", @"page": @(LSPageHr), @"type": @(LSTestTypePage)},
            @{@"title":@"体重", @"page": @(LSPageWeight), @"type": @(LSTestTypePage)},
            @{@"title":@"步数", @"page": @(LSPageStep), @"type": @(LSTestTypePage)},
            @{@"title":@"血压", @"page": @(LSPageBloodPressure), @"type": @(LSTestTypePage)},
            @{@"title":@"血糖", @"page": @(LSPageBloodSugar), @"type": @(LSTestTypePage)},
            @{@"title":@"我的设备", @"page": @(LSPageDeviceList), @"type": @(LSTestTypePage)},
            @{@"title":@"顾问中心", @"page": @(LSPageConsultantCenter), @"type": @(LSTestTypePage)},
            
            @{@"title":@"退出登录", @"type": @(LSTestTypeLogout)},
            
            
        ];
    }
    return _dataSouceAry;
}
@end
