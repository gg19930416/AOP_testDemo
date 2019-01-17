//
//  AOPInterceptor.m
//  AOP_TestDemo
//
//  Created by 郭刚 on 2019/1/17.
//  Copyright © 2019 郭刚. All rights reserved.
//

#import "AOPInterceptor.h"

@implementation AOPInterceptor {
    // 用来存刚放拦截者信息的字典,谁是拦截者,谁是被拦截者
    NSMutableDictionary * _interceptorClass;
}

// 单例实现
IMPLEMENTATION_SINGLETON(AOPInterceptor)

// 主入口,安装
+ (void)setup {
    [AOPInterceptor sharedInstance];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _interceptorClass = [NSMutableDictionary dictionary];
        // 初始化拦截者类
    }
    return self;
}

@end
