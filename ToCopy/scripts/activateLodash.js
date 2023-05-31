const _ = require('lodash');

hexo.extend.filter.register('template_locals', locals => {
  locals._ = _;
});
