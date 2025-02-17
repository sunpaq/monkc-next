#!/bin/sh

rm *.zip

xcodebuild -create-xcframework -library runtime/_build/archive/lib/libmonkc-runtime.a -headers runtime/_build/archive/include/ -output MonkC.xcframework
xcodebuild -create-xcframework -library stdlib/_build/archive/lib/libmonkc-stdlib.a -headers stdlib/_build/archive/include/ -output MonkCStdLib.xcframework
xcodebuild -create-xcframework -library platform/_build/archive/lib/libmonkc-platform.a -headers platform/_build/archive/include/ -output MonkCPlatformLib.xcframework

zip -r MonkC.xcframework.zip MonkC.xcframework
zip -r MonkCStdLib.xcframework.zip MonkCStdLib.xcframework
zip -r MonkCPlatformLib.xcframework.zip MonkCPlatformLib.xcframework

rm -rf *.xcframework

swift package compute-checksum MonkC.xcframework.zip
swift package compute-checksum MonkCStdLib.xcframework.zip
swift package compute-checksum MonkCPlatformLib.xcframework.zip
