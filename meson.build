project('mimic-full', 'c', default_options : ['c_std=c99'], version: '2.0.0')

c_compiler = meson.get_compiler('c')


includes = []
mimic_full_deps = []

mimic_modules = ['core', 'english', 'grapheme', 'indic']

foreach mimic_module : mimic_modules
  dep = dependency('ttsmimic_' + mimic_module, required: false)
  if not dep.found()
    # We compile it:
    dep_sub = subproject('mimic-@0@'.format(mimic_module))
    dep = dep_sub.get_variable('ttsmimic_@0@_dep'.format(mimic_module))
    includes += dep_sub.get_variable('includes')
  endif
  mimic_full_deps += dep
endforeach

mimic_voices = ['cmu_us_slt', 'vid_gb_ap', 'cmu_time_awb', 'cmu_us_awb', 'cmu_us_kal']

foreach mimic_voice : mimic_voices
  dep = dependency('ttsmimic_' + mimic_voice, required: false)
  if not dep.found()
    # We compile it:
    dep_sub = subproject('mimic-@0@'.format(mimic_voice))
    dep = dep_sub.get_variable('voice_dep')
    includes += dep_sub.get_variable('includes')
  endif
  mimic_full_deps += dep
endforeach



includes += [
  include_directories('include')
]

# Math library
m_dep = c_compiler.find_library('m', required : false)
dl_dep = c_compiler.find_library('dl', required: false)

executable('mimic-full', ['src/mimic_main.c', 'src/cst_builtin_plugins.c'],
           include_directories: includes,
           install: true,
           dependencies: [mimic_full_deps, m_dep, dl_dep])
