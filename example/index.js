const addon = require('../index')

const tesseract = new addon.Tesseract()
const outputText = tesseract.read(__dirname + '/example.png')

console.log(`
R E S U L T:

${outputText}
`)

const outputText2 = tesseract.read(__dirname + '/example.png')

console.log(`
R E S U L T 2:

${outputText2}
`)
