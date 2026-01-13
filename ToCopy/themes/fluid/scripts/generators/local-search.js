/* global hexo */

'use strict';

hexo.extend.generator.register('_hexo_generator_search', function(locals) {
  const config = this.theme.config;
  if (!config.search.enable) {
    return;
  }

  const nunjucks = require('nunjucks');
  const env = new nunjucks.Environment();
  const pathFn = require('path');
  const fs = require('fs');

  env.addFilter('uriencode', function(str) {
    return encodeURI(str);
  });

  env.addFilter('noControlChars', function(str) {
    // eslint-disable-next-line no-control-regex
    return str && str.replace(/[\x00-\x1F\x7F]/g, '');
  });

  env.addFilter('urlJoin', function(str) {
    const base = str[0];
    const relative = str[1];
    return relative
      ? base.replace(/\/+$/, '') + '/' + relative.replace(/^\/+/, '')
      : base;
  });

  function getSortedTags(tags) {
    if (!tags) return [];

    let arr;
    if (typeof tags.toArray === 'function') {
      arr = tags.toArray();
    } else if (Array.isArray(tags)) {
      arr = tags.slice();
    } else if (tags && Array.isArray(tags.data)) {
      arr = tags.data.slice();
    } else {
      arr = [];
    }

    arr.sort(function(a, b) {
      const an = a && a.name != null ? String(a.name) : '';
      const bn = b && b.name != null ? String(b.name) : '';
      if (typeof an.localeCompare === 'function') {
        try {
          return an.localeCompare(bn, undefined, {sensitivity: 'base'});
        } catch (e) {
          // ignore and fallback
        }
      }
      const al = an.toLowerCase();
      const bl = bn.toLowerCase();
      if (al < bl) return -1;
      if (al > bl) return 1;
      return 0;
    });

    return arr;
  }

  function addSortedTags(collection) {
    if (!collection || typeof collection.toArray !== 'function') return;
    collection.toArray().forEach(function(item) {
      if (item && item.tags && item.tags.length) {
        item.tags_sorted = getSortedTags(item.tags);
      }
    });
  }

  const searchTmplSrc = pathFn.join(hexo.theme_dir, './source/xml/local-search.xml');
  const searchTmpl = nunjucks.compile(fs.readFileSync(searchTmplSrc, 'utf8'), env);

  const searchConfig = config.search;
  let searchField = searchConfig.field;
  const content = searchConfig.content || true;

  let posts, pages;

  if (searchField.trim() !== '') {
    searchField = searchField.trim();
    if (searchField === 'post') {
      posts = locals.posts.sort('-date');
    } else if (searchField === 'page') {
      pages = locals.pages;
    } else {
      posts = locals.posts.sort('-date');
      pages = locals.pages;
    }
  } else {
    posts = locals.posts.sort('-date');
  }

  if (posts) {
    addSortedTags(posts);
  }
  if (pages) {
    addSortedTags(pages);
  }

  const xml = searchTmpl.render({
    config : config,
    posts  : posts,
    pages  : pages,
    content: content,
    url    : hexo.config.root
  });

  return {
    path: searchConfig.generate_path || '/local-search.xml',
    data: xml
  };
});
