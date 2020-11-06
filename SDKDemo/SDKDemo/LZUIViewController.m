//
//  LZUIViewController.m
//  SDKDemo
//
//  Created by wm on 2020/10/16.
//

#import "LZUIViewController.h"
#import <LSBluetoothUI_iOS/LSBluetoothUIManager.h>
#import <LSDeviceManagerFramework/LSDeviceManager.h>
#import <LSDeviceManagerFramework/LSDeviceManager+Connect.h>
#import <LSDeviceManagerFramework/LSDeviceManager+Device.h>

@interface LZUIViewController () <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *dataSouceAry;
@end

@implementation LZUIViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"乐智UI";
    self.view.backgroundColor = [UIColor whiteColor];
    [self createUI];
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

#pragma mark - event

- (void)HandlerClickCellItem:(NSDictionary *)item {
    if ([item[@"title"] isEqualToString:@"设备列表页"]) {
        [self.navigationController pushViewController:[[LSBluetoothUIManager shareInstance] lsPageDeviceList] animated:YES];
    }
    else if ([item[@"title"] isEqualToString:@"我的设备"]) {
        [self.navigationController pushViewController:[[LSBluetoothUIManager shareInstance] lsPageBindDeviceList] animated:YES];
    }
    else if ([item[@"title"] isEqualToString:@"体重"]) {
        [[LSBluetoothUIManager shareInstance] lsOpenWeightPage];
    }
    else if ([item[@"title"] isEqualToString:@"步数"]) {
        [[LSBluetoothUIManager shareInstance] lsStepPage];
    }
    else if ([item[@"title"] isEqualToString:@"睡眠"]) {
        [[LSBluetoothUIManager shareInstance] lsSleepRatePage];
    }
    else if ([item[@"title"] isEqualToString:@"心率"]) {
        [[LSBluetoothUIManager shareInstance] lsHeartRatePage];
    }
    else if ([item[@"title"] isEqualToString:@"血压"]) {
        [[LSBluetoothUIManager shareInstance] lsBloodpressurePage];
    }
    else if ([item[@"title"] isEqualToString:@"有氧能力"]) {
        [[LSBluetoothUIManager shareInstance] lsAerobicRatePage];
    }
    
}

#pragma mark - setter getter

- (NSArray *)dataSouceAry {
    if (!_dataSouceAry) {
        _dataSouceAry = @[@{@"title":@"睡眠"}
                          ,@{@"title":@"心率"}
                          ,@{@"title":@"体重"}
                          ,@{@"title":@"步数"}
                          ,@{@"title":@"血压"}
                          ,@{@"title":@"有氧能力"}
                          ,@{@"title":@"我的设备"}
                          ,@{@"title":@"设备列表页"}
      ];    }
    return _dataSouceAry;
}
@end
