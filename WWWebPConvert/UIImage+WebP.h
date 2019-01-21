//
//  UIImage+WebP.h
//  WWWebPConvert
//
//  Created by wangwei on 2019/1/21.
//  Copyright © 2019 wangwei. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "decode.h"
#include "encode.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (WebP)
+ (UIImage*)imageWithWebPData:(NSData*)imgData;

+ (UIImage*)imageWithWebP:(NSString*)filePath;

+ (NSData*)imageToWebP:(UIImage*)image compressionQuality:(CGFloat)quality;

+ (void)imageToWebP:(UIImage*)image
 compressionQuality:(CGFloat)quality
              alpha:(CGFloat)alpha
             preset:(WebPPreset)preset
    completionBlock:(void (^)(NSData* result))completionBlock
       failureBlock:(void (^)(NSError* error))failureBlock;

+ (void)imageToWebP:(UIImage*)image
 compressionQuality:(CGFloat)quality
              alpha:(CGFloat)alpha
             preset:(WebPPreset)preset
        configBlock:(void (^)(WebPConfig* config))configBlock
    completionBlock:(void (^)(NSData* result))completionBlock
       failureBlock:(void (^)(NSError* error))failureBlock;

+ (void)imageWithWebP:(NSString*)filePath
      completionBlock:(void (^)(UIImage* result))completionBlock
         failureBlock:(void (^)(NSError* error))failureBlock;

- (UIImage*)imageByApplyingAlpha:(CGFloat)alpha;
@end

NS_ASSUME_NONNULL_END
