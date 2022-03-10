//
//  UCloudReplayKitExtendsionControl.h
//  Pods
//
//  Created by ucloud on 2022/1/13.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <ReplayKit/ReplayKit.h>
NS_ASSUME_NONNULL_BEGIN

@class URTCReplayKitExtControl;
@protocol URTCReplayKitExtendsionControlDelegate <NSObject>

/**
 @brief Containning app 结束录屏回调

 @param extension URTCReplayKitExtControl
 */
- (void)urtReplayKitExtControlDidFinishBroadcast:(URTCReplayKitExtControl *)extension ;

@end
//API_AVAILABLE(ios(11.0))
@interface URTCReplayKitExtControl : NSObject

/**
 @brief 单例对象
 */
+ (instancetype)shared;

/**
 @brief 当前版本号
 */
+ (NSString *)currentVersion;

/**
 @brief Containning app 结束录屏回调
 @param appGroup App group ID
 @param delegate 结束录制回调
 */
- (void)setAppGroup:(NSString *)appGroup delegate:(id<URTCReplayKitExtendsionControlDelegate>)delegate;

/**
 @brief 暂停录屏
 @discussion 当 通过系统控制中心停止录屏时，会回调 RPBroadcastSampleHandler.broadcastPaused，在 broadcastPaused 方法中调用
 */
- (void)broadcastPaused;

/**
 @brief 暂停录屏
 @discussion 通过系统控制中心停止录屏时，会回调 RPBroadcastSampleHandler.broadcastResumed，在 broadcastResumed 方法中调用
 */
- (void)broadcastResumed;

/**
 @brief extension app 结束录屏
 @discussion 通过系统控制中心停止录屏时，会回调 RPBroadcastSampleHandler.broadcastFinished，在 broadcastFinished 方法中调用
 */
- (void)broadcastFinished;

/**
 @brief 发送视频到Containning app
 @param sampleBuffer 视频流
 @discussion 在 RPBroadcastSampleHandler 的实现类中的 processSampleBuffer: 方法中调用，发送给Containning app
 */
- (void)sendVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer;

@end


NS_ASSUME_NONNULL_END
