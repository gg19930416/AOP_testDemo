//
//  AOPSingleton.h
//  AOP_TestDemo
//
//  Created by 郭刚 on 2019/1/17.
//  Copyright © 2019 郭刚. All rights reserved.
//

#ifndef AOPSingleton_h
#define AOPSingleton_h

//定义单例模式类 INTERFACE_SINGLETON(类名)
#undef  INTERFACE_SINGLETON
#define INTERFACE_SINGLETON( __class) \
- (__class *)sharedInstance; \
+ (__class *)sharedInstance;

//实现单例模式类
#undef  IMPLEMENTATION_SINGLETON
#define IMPLEMENTATION_SINGLETON( __class) \
- (__class *)sharedInstance \
{ \
return [__class sharedInstance]; \
} \
+ (__class *)sharedInstance \
{ \
static dispatch_once_t once; \
static __class * __singleton__; \
dispatch_once( &once, ^{ __singleton__ = [[[self class] alloc] init]; } ); \
return __singleton__; \
} \

#endif /* AOPSingleton_h */
