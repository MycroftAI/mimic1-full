project('mimic-full', 'c', default_options : ['c_std=c99'], version: '2.0.0')

c_compiler = meson.get_compiler('c')

mimic_core = dependency('ttsmimiccore')
mimic_english = dependency('ttsmimicenglish')
mimic_cmu_us_slt = dependency('ttsmimic_cmu_us_slt')

mimic_full_deps = [mimic_core, mimic_english, mimic_cmu_us_slt]

includes = [
  include_directories('include')
]

# Math library
m_dep = c_compiler.find_library('m', required : false)
dl_dep = c_compiler.find_library('dl', required: false)

executable('mimic-full', ['src/mimic_main.c', 'src/cst_builtin_plugins.c'],
           include_directories: includes,
           install: true,
           dependencies: [mimic_full_deps, m_dep, dl_dep])
