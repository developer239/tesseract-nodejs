const addon = require('../index')

const tesseract = new addon.Tesseract()
const outputText = tesseract.read(__dirname + '/example.png')

console.log(`
R E S U L T:

${outputText}
`)
