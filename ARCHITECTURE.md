# Architecture and design planning

## Planned Design
![MVP](https://user-images.githubusercontent.com/165331/166068447-452c84a6-aa46-443b-8cef-e0ccc791fa44.png)

### Structures
_SlideGeneratorStrategy_ : The pattern of conformance for use by the generator. Adding support for a new format will come via this protocol.
_IntermediateSlideGenerator_ : The generator determines the input and output, and chooses the appropriate _strategies_ to use to accomplish the task. This internal logic is hidden from users, only offloading the conversion logic to strategy classes.

#### Intermediate slide formats
_IntermediateSlide_ : Contains 0 or more _IntermediateSlideElement_. Also has _title_, _label_, _labelColor_, and a dictionary of _metadata_ to inform other future or unknown features (constructed in _IntermediateSlideMetadata_).
_IntermediateSlideElement_ : Contains _styles_, _RTFData_ for fill text, and a _shapePath_. In cases where it is a simple rectangle with text, _shapePath_ will be the rectangle of four points indicating origin point and size.
_IntermediateSlideElementStyle_ : One or more of these can apply styles. The styleName string comes from the list of available constants. Some styles will be converted or ignored for some outputs, and this behavior is determined by the strategy implementation.

*Since this project is still in early development, the below is very much subject to change...*

## Future Design direction
![V2](https://user-images.githubusercontent.com/165331/166068511-ce31ddb4-ce9a-4046-a490-5a150903caf9.png)