# Tesseract Node.js

Node bindings for Tesseract OCR library. Currently, only supports Mac.

## Dependencies

In order to make this library work you have to install Tesseract on your machine. I highly recommend to just use `brew`. Otherwise, you can look [here and follow official installation instructions](https://github.com/tesseract-ocr/tesseract#installing-tesseract).

```
brew install tesseract
```

All you have to do after that is to install this library with `yarn` or `npm`.

```
yarn install tesseract-nodejs
```

## Example

```js
import { Tesseract } from 'tesseract-nodejs'

const tesseract = new Tesseract()
const outputText = tesseract.read(__dirname + '/example.png')

console.log(`
R E S U L T:

${outputText}
`)

// R E S U L T:
//
// { you will find Tesseract output here }
```

## TODO

- [ ] Fix the memory leak 😅
- [ ] Add support for more functions
- [ ] Add support for other systems (not likely to happen any time soon)
