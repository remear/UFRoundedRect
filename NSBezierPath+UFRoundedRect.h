//
//  NSBezierPath+UFRoundedRect.h
//
//  Created by Ben Mills on 03/23/2012.
//
/*
The MIT License

Copyright (c) 2012 Ben Mills

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#import <Cocoa/Cocoa.h>

@interface NSBezierPath (UFRoundedRect)
+ (NSBezierPath*)fourCornerRadiusRect:(NSRect)inRect tLRadius:(float)tLRadius tRRadius:(float)tRRadius bLRadius:(float)bLRadius bRRadius:(float)bRRadius;
@end

@implementation NSBezierPath (UFRoundedRect)

const float kEllipseFactor = 0.55228474983079;

+ (NSBezierPath*)fourCornerRadiusRect:(NSRect)inRect tLRadius:(float)tLRadius tRRadius:(float)tRRadius bLRadius:(float)bLRadius bRRadius:(float)bRRadius
{
    tLRadius = tLRadius * kEllipseFactor;
    tRRadius = tRRadius * kEllipseFactor;
    bLRadius = bLRadius * kEllipseFactor;
    bRRadius = bRRadius * kEllipseFactor;
    
    float controlTLEdges = tLRadius * kEllipseFactor;
    float controlTREdges = tRRadius * kEllipseFactor;
    float controlBLEdges = bLRadius * kEllipseFactor;
    float controlBREdges = bRRadius * kEllipseFactor;
    
    NSRect tLEdges = NSInsetRect(inRect, tLRadius, tLRadius);
    NSRect tREdges = NSInsetRect(inRect, tRRadius, tRRadius);
    NSRect bLEdges = NSInsetRect(inRect, bLRadius, bLRadius);
    NSRect bREdges = NSInsetRect(inRect, bRRadius, bRRadius);
    
    NSBezierPath *roundedRectPath = [NSBezierPath bezierPath];
    
    // Bottom right
    [roundedRectPath moveToPoint:NSMakePoint(bREdges.origin.x,inRect.origin.y)];
    [roundedRectPath lineToPoint:NSMakePoint(NSMaxX(bREdges),inRect.origin.y)];
    [roundedRectPath curveToPoint:NSMakePoint(NSMaxX(inRect),bREdges.origin.y)
              controlPoint1:NSMakePoint(NSMaxX(bREdges) + controlBREdges, inRect.origin.y)
              controlPoint2:NSMakePoint(NSMaxX(inRect), bREdges.origin.y - controlBREdges)];
    
    // Top right
    [roundedRectPath lineToPoint:NSMakePoint(NSMaxX(inRect), NSMaxY(tREdges))];
    [roundedRectPath curveToPoint:NSMakePoint(NSMaxX(tREdges), NSMaxY(inRect))
              controlPoint1:NSMakePoint(NSMaxX(inRect), NSMaxY(tREdges) + controlTREdges)
              controlPoint2:NSMakePoint(NSMaxX(tREdges) + controlTREdges, NSMaxY(inRect))];
    
    // Top left
    [roundedRectPath lineToPoint:NSMakePoint(tLEdges.origin.x, NSMaxY(inRect))];
    [roundedRectPath curveToPoint:NSMakePoint(inRect.origin.x, NSMaxY(tLEdges))
              controlPoint1:NSMakePoint(tLEdges.origin.x - controlTLEdges, NSMaxY(inRect))
              controlPoint2:NSMakePoint(inRect.origin.x, NSMaxY(tLEdges) + controlTLEdges)];
    
    // Bottom left
    [roundedRectPath lineToPoint:NSMakePoint(inRect.origin.x,bLEdges.origin.y)];
    [roundedRectPath curveToPoint:NSMakePoint(bLEdges.origin.x,inRect.origin.y)
              controlPoint1:NSMakePoint(inRect.origin.x,bLEdges.origin.y - controlBLEdges)
              controlPoint2:NSMakePoint(bLEdges.origin.x - controlBLEdges, inRect.origin.y)];
    
    [roundedRectPath closePath];

    return roundedRectPath;
}

@end