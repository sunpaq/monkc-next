#!/usr/bin/ruby
require 'mcbuild'

$runtime = MCBuild.new(__dir__)
	.set_name("monkc-runtime")
