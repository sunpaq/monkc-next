#!/bin/sh

rm MonkC.xcframework.zip

xcodebuild -create-xcframework -library runtime/_build/archive/lib/libmonkc-runtime.a -headers runtime/_build/archive/include/ -output MonkC.xcframework

zip -r MonkC.xcframework.zip MonkC.xcframework
rm -rf MonkC.xcframework

swift package compute-checksum MonkC.xcframework.zip
