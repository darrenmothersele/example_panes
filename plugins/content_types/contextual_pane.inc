<?php

// Stupid example of how to require a context to be passed to your pane

$plugin = array(
  'title' => t('User Links'),
  'single' => TRUE,
  'category' => array('Examples', -9),
  'edit form' => 'example_panes_user_links_edit_form',
  'render callback' => 'example_panes_user_links_render',
  'required context' => new ctools_context_required(t('User'), 'user'),
);

function example_panes_user_links_render($subtype, $conf, $context = NULL) {
  // If you have debug module you can see what's in the context...
  //dpm($context);

  $account = user_load($context[0]);
  $block->content = '<div class="example-user-link">' . l('Edit', 'user/' . $account->uid . '/edit') . '</div>';
  return $block;
}

function example_panes_user_links_edit_form($form, &$form_state) {
  // You can customise the edit form form for your pane
  // the value of any form items you add will be available in the $conf passed
  // to the render function
  $conf = $form_state['conf'];
  return $form;
}
