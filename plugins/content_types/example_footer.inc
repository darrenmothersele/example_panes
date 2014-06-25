<?php

$plugin = array(
  'title' => t('Example Footer'),
  'single' => TRUE,
  'category' => array('Examples', -9),
  'render callback' => 'example_panes_footer_render',
);

function example_panes_footer_render($subtype, $conf, $context = NULL) {
  $footer_menu = drupal_render(menu_tree('menu-footer-menu'));
  $block->content = theme('example_footer', array('menu' => $footer_menu));
  return $block;
}

