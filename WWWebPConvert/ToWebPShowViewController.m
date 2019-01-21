//
//  ToWebPShowViewController.m
//  WWWebPConvert
//
//  Created by wangwei on 2019/1/21.
//  Copyright © 2019 wangwei. All rights reserved.
//

#import "ToWebPShowViewController.h"
#import "UIImage+WebP.h"
@interface ToWebPShowViewController ()
@property (weak, nonatomic) IBOutlet UIImageView *imageView;

@end

@implementation ToWebPShowViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    UIImage *image = [UIImage imageNamed:@"test.PNG"];
    [UIImage imageToWebP:image
      compressionQuality:100
                   alpha:1
                  preset:WEBP_PRESET_DEFAULT
             configBlock:^(WebPConfig *config) {
                 config->sns_strength = 100.0f;
                 config->filter_strength = 0.0f;
                 config->method = 1;
                 config->preprocessing = 0;
                 config->filter_sharpness = 0;
                 config->thread_level = 1;
             } completionBlock:^(NSData *result) {
                 NSLog(@"--------webp转换成功");
                 dispatch_async(dispatch_get_main_queue(), ^{
                     self.imageView.image = [UIImage imageWithWebPData:result];
                 });
             } failureBlock:^(NSError *error) {
                 NSLog(@"webp图片转换失败%@",error.localizedDescription);
             }];
}


@end
