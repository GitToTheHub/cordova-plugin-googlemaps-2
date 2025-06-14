//
//  PluginUtil.h
//  cordova-googlemaps-plugin v2
//
//  Created by Masashi Katsumata.
//
//

#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>
#import "MainViewController.h"
#import <QuartzCore/QuartzCore.h>
#import <objc/runtime.h>
//#import "MFGoogleMapAdditions/GMSCoordinateBounds+Geometry.h"
#import "GMSCoordinateBounds+Geometry.h"
#import <math.h>
#import "IPluginProtocol.h"
#import "PluginViewController.h"
#import "PluginCAAnimationDelegate.h"
#import <Cordova/CDVCommandDelegate.h>

typedef void (^MYCompletionHandler)(NSError *error);

// Switch statement in Objective-C
//http://qiita.com/GeneralD/items/5a05f176ac2321e7a51b
#define CASE(str) if ([__s__ isEqualToString:(str)])
#define SWITCH(s) for (NSString *__s__ = (s); __s__; __s__ = nil)
#define DEFAULT

@interface UIView (GoogleMapsPlugin)
- (void)setFrameWithDictionary:(NSDictionary *) params;
- (void)setFrameWithInt:(int)left top:(int)top width:(int)width height:(int)height;
@end

@interface NSArray (GoogleMapsPlugin)
- (UIColor*)parsePluginColor;
@end

@interface NSString (GoogleMapsPlugin)
- (NSString*)regReplace:(NSString*)pattern replaceTxt:(NSString*)replaceTxt options:(NSRegularExpressionOptions)options;
@end


@interface UIImage (GoogleMapsPlugin)
- (UIImage*)imageByApplyingAlpha:(CGFloat) alpha;
- (UIImage *)resize:(CGFloat)width height:(CGFloat)height;
@end


@interface PluginUtil : NSObject
+ (BOOL)isPolygonContains:(GMSPath *)path coordinate:(CLLocationCoordinate2D)coordinate projection:(GMSProjection *)projection;
+ (CLLocationCoordinate2D)isPointOnTheLine:(GMSPath *)path coordinate:(CLLocationCoordinate2D)coordinate projection:(GMSProjection *)projection;
+ (CLLocationCoordinate2D)isPointOnTheGeodesicLine:(GMSPath *)path coordinate:(CLLocationCoordinate2D)coordinate threshold:(double)threshold projection:(GMSProjection *)projection;
+ (BOOL)isCircleContains:(GMSCircle *)circle coordinate:(CLLocationCoordinate2D)point;
+ (BOOL)isInDebugMode;
+ (GMSMutablePath *)getMutablePathFromCircle:(CLLocationCoordinate2D)center radius:(double)radius;
+ (NSString *)getAbsolutePathFromCDVFilePath:(UIView*)theWebView cdvFilePath:(NSString *)cdvFilePath;
+ (NSString *)PGM_LOCALIZATION:(NSString *)key;
+ (void)getJsonWithURL:(NSString *)baseUrlStr params:(NSDictionary *)params completionBlock:(void (^)(BOOL succeeded, NSDictionary *response, NSString *error))completionBlock;
+ (void)getJsonWithURL:(NSURL *)url completionBlock:(void (^)(BOOL succeeded, NSDictionary *response, NSString *error))completionBlock;
+ (double)getZoomFromBounds:(GMSCoordinateBounds *)bounds mapWidth:(double)mapWidth mapHeight:(double)mapHeight;
+ (double)_zoom:(double)mapPx worldPx:(double)worldPx fraction:(double)fraction;
+ (double)_latRad:(double)lat;
@end



@implementation UIGestureRecognizer (Cancel)
- (void)cancel {
    self.enabled = NO;
    self.enabled = YES;
}
@end



@interface CDVPlugin (GoogleMapsPlugin)
- (void)setPluginViewController: (PluginViewController*)viewCtrl;
@end
