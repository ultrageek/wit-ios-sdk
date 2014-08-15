//
//  WITRecordingSession.h
//  Wit
//
//  Created by Aric Lasry on 8/14/14.
//  Copyright (c) 2014 Willy Blandin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WITSessionToggle.h"
#import "WITRecorder.h"
#import "WITUploader.h"
#import "WITVadTracker.h"
#import "WitPrivate.h"

@protocol WITRecordingSessionDelegate <NSObject>
-(void)recorderGotChunk:(NSData*)chunk;
-(void)gotResponse:(NSDictionary*)resp error:(NSError*)err;
@end

@interface WITRecordingSession : NSObject <WITRecorderDelegate, WITUploaderDelegate>

@property NSObject <WITSessionToggle> *starter;
@property WITRecorder *recorder;
@property WITUploader *uploader;
@property NSObject <WITRecordingSessionDelegate> *delegate;



-(id)initWithWitContext:(NSDictionary *)upContext vadEnabled:(BOOL)vadEnabled withToggleStarter:(id <WITSessionToggle>) starter;
-(void)stop;
-(BOOL)isRecording;
-(void)trackVad:(NSString *)messageId;

@end


