#ruby script!!! eshm3na :D
#!/bin/env ruby
require 'getopts'

seedoffset = 0

if getopts( "s:" ) == nil ||  ARGV.length == 0 || $OPT_h then
	puts "Usage: #{$0} [-s number_of_seeds] input_files"
	exit
end

if $OPT_s
    seedoffset = $OPT_s.to_i
end


files = ARGV


num = seedoffset + 1
for file in files
	output = ""
	STDERR.puts file
	fp = File.open( file, "r" )
	while line = fp.gets
		if line =~ /^>/ then
			output += " " + num.to_s
			num += 1
		end
	end
	fp.close
	puts output + "  # " + file
end
