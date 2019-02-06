/*
 * Copyright 2017 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, FIRIAMRenderTrigger) {
  FIRIAMRenderTriggerOnAppForeground,
  FIRIAMRenderTriggerOnFirebaseAnalyticsEvent
};

NS_ASSUME_NONNULL_BEGIN
@interface FIRIAMDisplayTriggerDefinition : NSObject
@property(nonatomic, readonly) FIRIAMRenderTrigger triggerType;

// applicable only when triggerType == FIRIAMRenderTriggerOnFirebaseAnalyticsEvent
@property(nonatomic, copy, nullable, readonly) NSString *firebaseEventName;

- (instancetype)initForAppForegroundTrigger;
- (instancetype)initWithFirebaseAnalyticEvent:(NSString *)title;
@end
NS_ASSUME_NONNULL_END
