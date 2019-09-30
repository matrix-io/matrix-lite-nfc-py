from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools

__version__ = '0.0.1'

ext_modules = [
    Extension(
        'hal_nfc',
        sources=[
            'hal_nfc_wrapper/reader/read.cpp',
            'hal_nfc_wrapper/nfc.cpp',
        ],
        include_dirs=[
            "/usr/local/include/python3.7",
            "/usr/local/include/matrix_nfc/nxp_nfc/NxpNfcRdLib/intfs",
            "/usr/local/include/matrix_nfc/nxp_nfc/NxpNfcRdLib/types",
        ],
        libraries=["matrix_hal_nfc"],
        extra_compile_args=[
            "-DNXPBUILD__PH_RASPBERRY_PI",
        ],
        language='c++'
    ),
]

class BuildExt(build_ext):
    """A custom build extension for adding compiler-specific options."""
    c_opts = {'unix': [],}
    l_opts = {'unix': [],}

    def build_extensions(self):
        ct = self.compiler.compiler_type
        opts = self.c_opts.get(ct, [])
        link_opts = self.l_opts.get(ct, [])

        # fix extra_compile_args being ignored
        for arg in ext_modules[0].extra_compile_args: 
            opts.append(arg)     

        opts.append('-DVERSION_INFO="%s"' % self.distribution.get_version())
        opts.append('-std=c++11')

        for ext in self.extensions:
            ext.extra_compile_args = opts
            ext.extra_link_args = link_opts

        build_ext.build_extensions(self)

setup(
    name='matrix_lite_nfc',
    version=__version__,
    author='MATRIX',
    packages=['matrix_lite_nfc',],
    url='https://github.com/matrix-io/matrix-lite-nfc-py',
    description='A test project using pybind11',
    long_description='',
    ext_modules=ext_modules,
    install_requires=['pybind11>=2.4'],
    setup_requires=['pybind11>=2.4'],
    cmdclass={'build_ext': BuildExt},
    zip_safe=False,
)