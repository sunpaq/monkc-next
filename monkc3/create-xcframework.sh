#!/bin/sh

xcodebuild -create-xcframework -library runtime/_build/archive/lib/libmonkc-runtime.a -headers runtime/_build/archive/include/ -output MonkC.xcframework