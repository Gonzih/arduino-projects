#!/usr/bin/env ruby

require 'serialport'

port = Dir.glob('/dev/ttyACM*').first
sp = SerialPort.new(port, 9600)
sp.write('A') # use channel A
turbo = false

loop do
  system("stty raw -echo")
  char = STDIN.getc
  system("stty -raw echo")
  case char
  when '5'
    if turbo then sp.write('a') else sp.write('1') end
  when '2'
    if turbo then sp.write('b') else sp.write('2') end
  when '4'
    if turbo then sp.write('c') else sp.write('3') end
  when '6'
    if turbo then sp.write('d') else sp.write('4') end
  when '1'
    if turbo then sp.write('e') else sp.write('5') end
  when '3'
    if turbo then sp.write('f') else sp.write('6') end
  when '7'
    sp.write('7')
  when '9'
    sp.write('8')
  when '+'
    turbo = !turbo
  end
  break if char == 'q'
end

sp.close
