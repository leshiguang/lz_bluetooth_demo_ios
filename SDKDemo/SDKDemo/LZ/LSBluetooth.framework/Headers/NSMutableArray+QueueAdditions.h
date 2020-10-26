//
//  NSMutableArray+QueueAdditions.h
//  LSBluetooth-Library
//
//  Created by lifesense on 15/7/9.
//  Copyright (c) 2015年 Lifesense. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableArray (QueueAdditions)

//从队列中获取第一个元素,且执行删除操作
-(id)lsble_dequeue;

//从队列中获取第一个元素，但不删除
-(id) lsble_peekqueue;

//向队列中插入一个元素
-(void) lsble_enqueue:(id)obj;

@end
