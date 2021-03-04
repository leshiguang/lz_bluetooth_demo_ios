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

@interface ViewController () <UITableViewDelegate, UITableViewDataSource>
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
    LSBluetoothUIConfig *config = [[LSBluetoothUIConfig alloc] init];
    config.appKey = @"lxd81836bc0ffa8084";
    config.appSecret = @"d7c3ad483bebe3c99b67b521b96efad0d5d8c4d1";
    config.tn = @"dingding";
    config.debug = YES;
    [LSBluetoothUI initWithConfig:config];
    
    /// 登陆
    [LSBluetoothUI loginWithAssociatedId:@"tanjian" completion:^(BOOL result) {
        NSLog(@"登陆是否成功 %@", @(result));
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
