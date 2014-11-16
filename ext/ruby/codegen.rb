EFFECTS = [
  "BoingBoing",
  "BoxShrinkGrow",
  "BoxWoopWoop",
  "FlowingBox",
  "GameOfLife",
  "RandomSparkle",
  "Ripples",
  "Stairs",
  "Suspend",
  "UpDown",
  "WormSqueeze"
]

OUPTUT_PATH = "/home/dalmir/storage/microcontroller/arduino/cube/ArduinoCube/src/effects"

def generate_h
  EFFECTS.each do |effect|
    puts "generating h for #{effect}"
    f = File.open(File.join(OUPTUT_PATH, effect) + ".h", "w")
    f.puts "/**"
    f.puts " */"
    f.puts ""
    f.puts "#ifndef __ARDUINO_CUBE_EFFECTS_#{effect.upcase}_H__"
    f.puts "#define __ARDUINO_CUBE_EFFECTS_#{effect.upcase}_H__ 1"
    f.puts ""
    f.puts "#include <Effect.h>"
    f.puts "#include <Cube.h>"
    f.puts ""
    f.puts "class #{effect.capitalize} : public Effect {"
    f.puts ""
    f.puts "public:"
    f.puts ""
    f.puts "  typedef struct {"
    f.puts "    unsigned char iterations;"
    f.puts "  } #{effect.capitalize}Parameters;"
    f.puts ""
    f.puts "  #{effect.capitalize}Parameters *parameters;"
    f.puts ""
    f.puts "  #{effect.capitalize}(Cube *cube, #{effect.capitalize}Parameters *parameters);"
    f.puts ""
    f.puts "  virtual void run();"
    f.puts "};"
    f.puts ""
    f.puts "#endif /* __ARDUINO_CUBE_EFFECTS_#{effect.upcase}_H__ */"
    f.close()
  end
end

def generate_cpp
  EFFECTS.each do |effect|
    puts "generating cpp for #{effect}"
    f = File.open(File.join(OUPTUT_PATH, effect) + ".cpp", "w")
    f.puts "/**"
    f.puts " */"
    f.puts ""
    f.puts "#ifndef __ARDUINO_CUBE_EFFECTS_#{effect.upcase}_CPP__"
    f.puts "#define __ARDUINO_CUBE_EFFECTS_#{effect.upcase}_CPP__ 1"
    f.puts ""
    f.puts "#include <#{effect.capitalize}.h>"
    f.puts ""
    f.puts "#{effect.capitalize}::#{effect.capitalize}(Cube *cube, #{effect.capitalize}Parameters *parameters) : Effect(cube), parameters(parameters) {"
    f.puts "}"
    f.puts ""
    f.puts "void #{effect.capitalize}::run() {"
    f.puts "  for (int it = 0; it < parameters->iterations; it++) {"
    f.puts "  }"
    f.puts "}"
    f.puts ""
    f.puts "#endif /* __ARDUINO_CUBE_EFFECTS_#{effect.upcase}_CPP__ */"
    f.close()
  end
end

generate_h
generate_cpp
