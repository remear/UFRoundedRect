# NSBezierPath+UFRoundedRect.h

NSBezierPath+UFRoundedRect.h is an Objective-C category for drawing a rounded rectangle with the ability to specify a radius for each corner.

### Installing
Run ```git://github.com/remear/UFRoundedRect.git```
Copy NSBezierPath+UFRoundedRect.h to your Xcode project

### Usage
Add ```#import "NSBezierPath+UFRoundedRect.h"```. Typically this is done in an NSView subclass


Call ```NSBezierPath *roundedRect = [NSBezierPath fourCornerRadiusRect:dirtyRect tLRadius:8.0 tRRadius:8.0 bLRadius:8.0 bRRadius:8.0];```