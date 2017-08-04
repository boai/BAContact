#BAContact
[![BAHome Team Name](https://img.shields.io/badge/Team-BAHome-brightgreen.svg?style=flat)](https://github.com/BAHome "BAHome Team")
![](https://img.shields.io/badge/platform-iOS-red.svg) ![](https://img.shields.io/badge/language-Objective--C-orange.svg) 
![](https://img.shields.io/badge/license-MIT%20License-brightgreen.svg) 
![](https://img.shields.io/cocoapods/v/BAContact.svg?style=flat) ![](https://img.shields.io/cocoapods/dt/BAContact.svg
)  [![](https://img.shields.io/badge/微博-博爱1616-red.svg)](http://weibo.com/538298123)

## 1、功能及简介
* 1、通讯录，最简单的中英文混合排序封装，微信通讯录 demo！<br>
* 2、获取系统通讯录内容，然后添加到自定义通讯录<br>

## 2、图片示例
![BAContact1.png](https://github.com/BAHome/BAContact/blob/master/Images/BAContact1.png)
![BAContact2.png](https://github.com/BAHome/BAContact/blob/master/Images/BAContact2.png)
![BAContact3.png](https://github.com/BAHome/BAContact/blob/master/Images/BAContact3.png)

## 3、安装、导入示例和源码地址
* 1、pod 导入【最新版本：![](https://img.shields.io/cocoapods/v/BAContact.svg?style=flat)】： <br>
 `pod 'BAContact'`  <br>
如果发现 `pod search BAContact` 搜索出来的不是最新版本，需要在终端执行 cd 转换文件路径命令退回到 desktop，然后执行 `pod setup` 命令更新本地spec缓存（可能需要几分钟），然后再搜索就可以了。<br>
具体步骤：
  - pod setup : 初始化
  - pod repo update : 更新仓库
  - pod search BAContact
* 2、文件夹拖入：下载demo，把 BAContact 文件夹拖入项目即可，<br>
* 3、导入头文件：<br>
`  #import "BAContact.h" `<br>
* 4、项目源码地址：<br>
 OC 版 ：[https://github.com/BAHome/BAContact](https://github.com/BAHome/BAContact)<br>

## 4、BAContact 的类结构及 demo 示例
![BAContact.png](https://github.com/BAHome/BAContact/blob/master/Images/BAContact.png)

### BAContact.h
```
#ifndef BAContact_h
#define BAContact_h


// 系统自带的中英文混合排序
#import "BAKit_LocalizedIndexedCollation.h"

#import "BAKit_ConfigurationDefine.h"
#import "UIImage+BAContact.h"

/*!
 *********************************************************************************
 ************************************ 更新说明 ************************************
 *********************************************************************************
 
 欢迎使用 BAHome 系列开源代码 ！
 如有更多需求，请前往：https://github.com/BAHome
 
 项目源码地址：
 OC 版 ：https://github.com/BAHome/BAContact
 
 最新更新时间：2017-08-05 【倒叙】 <br>
 最新Version：【Version：1.0.0】 <br>
 更新内容： <br>
 1.0.0.1、通讯录，最简单的中英文混合排序封装，微信通讯录 demo！ <br>
 1.0.0.2、获取系统通讯录内容，然后添加到自定义通讯录 <br>
 */

#endif /* BAContact_h */
```

### BAKit_LocalizedIndexedCollation.h
```
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

/*! 索引 */
#define kBALocalizedIndexArrayKey @"kBALocalizedIndexArrayKey"
/*! 排序后的分组，可以为 model */
#define kBALocalizedGroupArrayKey @"kBALocalizedGroupArrayKey"

@interface BAKit_LocalizedIndexedCollation : NSObject

/*!
 对数组排序
 
 @param dataArray        需要排序的数组，可以为 model
 @param localizedNameSEL 数组中对象需要排序的属性，可以为 model.userName
 
 @return 排序后的索引及 groupArray 字典形式 kBALocalizedIndexArrayKey kBALocalizedGroupArrayKey
 */
+ (NSDictionary *)ba_localizedWithDataArray:(NSMutableArray *)dataArray
                           localizedNameSEL:(SEL)localizedNameSEL;

@end
```

### demo 示例
```
- (void)getSectionData
{
    NSDictionary *dict = [BAKit_LocalizedIndexedCollation ba_localizedWithDataArray:self.dataArray localizedNameSEL:@selector(user_Name)];
    self.indexArray   = dict[kBALocalizedIndexArrayKey];
    self.sectionArray = dict[kBALocalizedGroupArrayKey];
    
    NSMutableArray *tempModel = [[NSMutableArray alloc] init];
    NSArray *dicts = @[@{@"user_Name" : @"新的朋友",
                         @"user_Image_url" : @"plugins_FriendNotify"},
                       @{@"user_Name" : @"群聊",
                         @"user_Image_url" : @"add_friend_icon_addgroup"},
                       @{@"user_Name" : @"标签",
                         @"user_Image_url" : @"Contact_icon_ContactTag"},
                       @{@"user_Name" : @"公众号",
                         @"user_Image_url" : @"add_friend_icon_offical"}];
    for (NSDictionary *dict in dicts)
    {
        BAContactsModel *model = [BAContactsModel new];
        model.user_Name = dict[@"user_Name"];
        model.user_Image_url = dict[@"user_Image_url"];
        [tempModel addObject:model];
    }
    
    [self.sectionArray insertObject:tempModel atIndex:0];
    [self.indexArray insertObject:@"🔍" atIndex:0];
    
    [self.tableView reloadData];
}

其他示例可下载demo查看源码！
```

## 5、更新记录：【倒叙】
 欢迎使用 [【BAHome】](https://github.com/BAHome) 系列开源代码 ！
 如有更多需求，请前往：[【https://github.com/BAHome】](https://github.com/BAHome) 
 
 
 最新更新时间：2017-08-05 【倒叙】 <br>
 最新Version：【Version：1.0.0】 <br>
 更新内容： <br>
 1.0.0.1、通讯录，最简单的中英文混合排序封装，微信通讯录 demo！ <br>
 1.0.0.2、获取系统通讯录内容，然后添加到自定义通讯录 <br>

## 6、bug 反馈
> 1、开发中遇到 bug，希望小伙伴儿们能够及时反馈与我们 BAHome 团队，我们必定会认真对待每一个问题！ <br>

> 2、以后提需求和 bug 的同学，记得把 git 或者博客链接给我们，我直接超链到你们那里！希望大家积极参与测试！<br> 

## 7、BAHome 团队成员
> 1、QQ 群 
 479663605 <br> 
【注意：此群为 2 元 付费群，介意的小伙伴儿勿扰！】<br> 

> 孙博岩 <br> 
QQ：137361770 <br> 
git：[https://github.com/boai](https://github.com/boai) <br>
简书：[http://www.jianshu.com/u/95c9800fdf47](http://www.jianshu.com/u/95c9800fdf47) <br>
微博：[![](https://img.shields.io/badge/微博-博爱1616-red.svg)](http://weibo.com/538298123) <br>

> 马景丽 <br> 
QQ：1253540493 <br> 
git：[https://github.com/MaJingli](https://github.com/MaJingli) <br>

> 陆晓峰 <br> 
QQ：442171865 <br> 
git：[https://github.com/zeR0Lu](https://github.com/zeR0Lu) <br>

> 陈集 <br> 
QQ：3161182978 <br> 
git：[https://github.com/chenjipdc](https://github.com/chenjipdc) <br>
简书：[http://www.jianshu.com/u/90ae559fc21d](http://www.jianshu.com/u/90ae559fc21d)

> 任子丰 <br> 
QQ：459643690 <br> 
git：[https://github.com/renzifeng](https://github.com/renzifeng) <br>

> 吴丰收 <br> 
QQ：498121294 <br> 

> 石少庸 <br> 
QQ：363605775 <br> 
git：[https://github.com/CrazyCoderShi](https://github.com/CrazyCoderShi) <br>
简书：[http://www.jianshu.com/u/0726f4d689a3](http://www.jianshu.com/u/0726f4d689a3)

> 丁寅初 <br> 
QQ：1137155216 <br> 
git：[https://github.com/1137155216](https://github.com/1137155216) <br>
博客园：[http://www.cnblogs.com/ios-dyc1998](http://www.cnblogs.com/ios-dyc1998)

> 唐海洋 <br> 
QQ：790015339 <br> 
git：[https://github.com/tanghaiyang1992](https://github.com/tanghaiyang1992) <br>
简书：[http://www.jianshu.com/u/b833cfd6bd58](http://www.jianshu.com/u/b833cfd6bd58)

> 权军刚 <br> 
QQ：906910380 <br> 
git：[https://github.com/Gang679](https://github.com/Gang679) <br>
简书：[http://www.jianshu.com/u/ab83189244d9](http://www.jianshu.com/u/ab83189244d9)

## 8、开发环境 和 支持版本
> 开发使用 最新版本 Xcode，理论上支持 iOS 8 及以上版本，如有版本适配问题，请及时反馈！多谢合作！

## 9、感谢
> 感谢 [BAHome](https://github.com/BAHome) 团队成员倾力合作，后期会推出一系列 常用 UI 控件的封装，大家有需求得也可以在 issue 提出，如果合理，我们会尽快推出新版本！<br>

> [BAHome](https://github.com/BAHome) 的发展离不开小伙伴儿的信任与推广，再次感谢各位小伙伴儿的支持！

