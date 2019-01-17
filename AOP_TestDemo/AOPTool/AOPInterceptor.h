//
//  AOPInterceptor.h
//  AOP_TestDemo
//
//  Created by 郭刚 on 2019/1/17.
//  Copyright © 2019 郭刚. All rights reserved.
//  2.拦截框架WBWInterceptor头文件内容

#import <Foundation/Foundation.h>
#import "AOPSingleton.h"
#import "objc/runtime.h"

NS_ASSUME_NONNULL_BEGIN

// 两个key的宏定义
#define kAOPInterceptorPropertyKey             @"kAOPInterceptorPropertyKey"
#define KAOPInterceptedInstancePropertyKey     @"KAOPINterceptedInstancePropertyKey"

// 被拦截者方法宏, 让拦截者添加被拦截者
/**
 1.第一个方法,返回被拦截者的类
 2.set方法 运行时动态的为拦截者类关联一个被拦截者类属性,类似set方法
 3.get方法 运行时动态为拦截者类关联一个被拦截者属性,类似get方法
 */
#undef INTERCEPT_CLASS
#define INTERCEPT_CLASS( __class ) \
+ (Class)interceptedClass \
{ \
return [__class class]; \
} \
- (void)setInterceptedInstance:(__class *)instance \
{ \
objc_setAssociatedObject(self, kWBWInterceptedInstancePropertyKey, instance, OBJC_ASSOCIATION_ASSIGN);\
} \
- (__class *)interceptedInstance \
{ \
id interceptedInstance = objc_getAssociatedObject(self, kWBWInterceptedInstancePropertyKey); \
return (__class *)interceptedInstance;\
} \

// 拦截者协议,安装的时候会用运行时遍历所有的类,只是遵循了拦截者协议的类才能成为拦截者
@protocol AOPInterceptorProtocol <NSObject>

@end

@interface AOPInterceptor : NSObject
// 单例声明
INTERFACE_SINGLETON(AOPInterceptor)

// 主入口,安装
+ (void)setup;

@end

NS_ASSUME_NONNULL_END
