from conan import ConanFile


class Recipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps", "VirtualRunEnv"

    def layout(self):
        self.folders.generators = "conan"

    def requirements(self):
        self.requires("fmt/10.0.0")
        self.requires("cpp-httplib/0.12.5")
        self.requires("nlohmann_json/3.11.2")


    def build_requirements(self):
        self.test_requires("catch2/3.3.2")
