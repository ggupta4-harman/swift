@import Foundation;
@import SwiftName;

@interface PointerWrapper
@property void *_Null_unspecified voidPtr;
@property int *_Null_unspecified intPtr;
@property _Null_unspecified id __autoreleasing *_Null_unspecified idPtr;
@end

#pragma clang assume_nonnull begin
@interface SwiftNameTest : NSObject

// "Factory methods" that we'd rather have as initializers.
+ (instancetype)a SWIFT_NAME(init());
+ (instancetype)b SWIFT_NAME(init(dummyParam:));
+ (instancetype)c:(nullable id)x SWIFT_NAME(init(cc:));
+ (instancetype):(int)x SWIFT_NAME(init(empty:));

// Would-be initializers.
+ (instancetype)testZ SWIFT_NAME(zz());
+ (instancetype)testY:(nullable id)x SWIFT_NAME(yy(aa:));
+ (instancetype)testX:(nullable id)x xx:(nullable id)xx SWIFT_NAME(xx(_:bb:));
+ (instancetype):(int)x :(int)y SWIFT_NAME(empty(_:_:));

// Things that Clang won't catch as problematic, but we should.
+ (instancetype)f:(id)x SWIFT_NAME(init(f:ff:));
+ (instancetype)g:(id)x outParam:(int *)foo SWIFT_NAME(init(g:));
+ (instancetype)testW:(id)x out:(id *)outObject SWIFT_NAME(ww(_:));
+ (instancetype)test SWIFT_NAME(test(a:b:));
+ (instancetype)test:(id)x more:(id)y SWIFT_NAME(test());

- (void)methodInt:(NSInteger)value SWIFT_NAME(theMethod(number:));
- (void):(NSInteger)a b:(NSInteger)b SWIFT_NAME(empty(a:b:));

@property (readonly) int someProp SWIFT_NAME(renamedSomeProp);
@property (readonly, class) int classProp SWIFT_NAME(renamedClassProp);
@end

@interface SwiftNameTestError : NSObject
// Factory methods with NSError.
+ (nullable instancetype)err1:(NSError **)err SWIFT_NAME(init(error:));
+ (nullable instancetype)err2:(nullable id)x error:(NSError **)err SWIFT_NAME(init(aa:error:));
+ (nullable instancetype)err3:(nullable id)x error:(NSError **)err callback:(void(^)(void))block SWIFT_NAME(init(aa:error:block:));
+ (nullable instancetype)err4:(NSError **)err callback:(void(^)(void))block SWIFT_NAME(init(error:block:));

+ (nullable instancetype)err5:(nullable id)x error:(NSError **)err SWIFT_NAME(init(aa:));
+ (nullable instancetype)err6:(nullable id)x error:(NSError **)err callback:(void(^)(void))block SWIFT_NAME(init(aa:block:));
+ (nullable instancetype)err7:(NSError **)err callback:(void(^)(void))block SWIFT_NAME(init(block:));

// Would-be initializers.
+ (nullable instancetype)testW:(nullable id)x error:(NSError **)err SWIFT_NAME(ww(_:));
+ (nullable instancetype)testW2:(nullable id)x error:(NSError **)err SWIFT_NAME(w2(_:error:));
+ (nullable instancetype)testV:(NSError **)err SWIFT_NAME(vv());
+ (nullable instancetype)testV2:(NSError **)err SWIFT_NAME(v2(error:));
@end

@interface SwiftNameTestSub : SwiftNameTest
@end

@interface SwiftNameTestErrorSub : SwiftNameTestError
@end

@interface SwiftGenericNameTest<T> : NSObject
@end

@interface SwiftConstrGenericNameTest<T:NSNumber *> : NSNumber
@end

int global_int SWIFT_NAME(GlobalInt);

@compatibility_alias SwiftNameAlias SwiftNameTest;
@compatibility_alias SwiftGenericNameAlias SwiftGenericNameTest;
@compatibility_alias SwiftConstrGenericNameAlias SwiftConstrGenericNameTest;

#pragma clang assume_nonnull end
