'use strict';

/* global hexo */

function normalizeTagList(tags) {
  if (!tags) return [];

  if (Array.isArray(tags)) {
    return tags.slice();
  }

  if (tags && typeof tags.toArray === 'function') {
    return tags.toArray();
  }

  if (tags && Array.isArray(tags.data)) {
    return tags.data.slice();
  }

  return [];
}

function compareTagName(a, b) {
  var an = a && a.name ? String(a.name) : '';
  var bn = b && b.name ? String(b.name) : '';

  if (typeof an.localeCompare === 'function') {
    try {
      return an.localeCompare(bn, undefined, {sensitivity: 'base'});
    } catch (e) {
      // ignore and fallback
    }
  }

  an = an.toLowerCase();
  bn = bn.toLowerCase();

  if (an < bn) return -1;
  if (an > bn) return 1;
  return 0;
}

function sortTags(tags) {
  var list = normalizeTagList(tags);
  list.sort(compareTagName);
  return list;
}

hexo.extend.helper.register('sorted_tags', function(tags) {
  return sortTags(tags);
});
