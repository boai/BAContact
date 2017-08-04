//
//  UIImage+BAContact.h
//  BAContact
//
//  Created by boai on 2017/8/3.
//  Copyright © 2017年 boai. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (BAContact)

/*!
 获得新的圆形图片
 
 @param image 传入需要裁剪成圆形的图片
 @return 返回裁剪好的圆形图片
 */
+ (UIImage *)ba_imageToRoundImageWithImage:(UIImage *)image;

/*!
 *  传入图片，cell，imageSize，改变自定义大小的圆形系统 cell image
 *
 *  @param cell      cell
 *  @param image     image 可以自己切圆角：[UIImage ba_imageToRoundImageWithImage:UIImageMake(@"icon1.jpg")]；
 *  @param imageSize 图像的 size 记得先切圆角再传 size
 *
 *  @return 返回自定义大小的圆形系统 cell image
 */
+ (UIImage *)ba_imageToChangeCellRoundImageViewSizeWithCell:(UITableViewCell *)cell
                                                      image:(UIImage *)image
                                                  imageSize:(CGSize)imageSize;

@end

@interface NSString (BAContact)

/**
 判断 string 是否为空
 
 @return YES：为空，NO：不为空
 */
- (BOOL)ba_stringIsBlank;

/**
 判断一个字符串里面是否包含另一个字符串
 
 @param string string
 @return YES/NO
 */
- (BOOL)ba_stringIncludesString:(NSString *)string;

@end
