const addon = require('bindings')({
  bindings: 'tesseract-nodejs', // TODO: figure out a better way to do this?
  try: [['module_root', 'cpp', 'build', 'Release', 'bindings']]
})

module.exports = {
  Tesseract: addon.Tesseract
}
