# SlideConverters
A shared library for converting between documents and slide formats for church slideshows

## Goals
- **Publish regular packages** for use in open-source projects. The hope would be to regularly update packages on the Swift/Cocoapods.
- **Provide support for key document types to start:** ProPresenter 7, Apple Pages, and RTF. Add other formats using additional strategies. These additional strategies can inform the architecture, but no specific format should dictate the project architecture as a whole. (For example, supporting PowerPoint should not break support for ProPresenter 7 or lead to excessive complexity not needed by ProPresenter 7.)
- **Provide automatic templating during slide conversion.** Strategies may, during conversion, use logic about the contents of the input document to determine the output template for a slide.
- **Regular CI/CD to upload package updates after asserting tests pass.** Tests should cover the strategies to ensure they always acheive their desired output for a given input.

## Planned Design
![MVP](https://user-images.githubusercontent.com/165331/166068447-452c84a6-aa46-443b-8cef-e0ccc791fa44.png)
More information can be found in [ARCHITECTURE.md](ARCHITECTURE.md).

## ACK

- C++ started from this starter pack: https://github.com/TheLartians/ModernCppStarter
- Research for Swift on Android: https://medium.com/android-news/swift-for-android-our-experience-and-tools-7a2f0ba58ab3
- Swift on Windows: https://www.swift.org/blog/swift-on-windows/
