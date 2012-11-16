<?php

/**
 * @file
 * Administration interface for the Finurlig Widget module is implemented in this
 * file. It give site administrators an option to change the wigdets behaviour.
 *
 */


/**
 * Implements the administration form for the module.
 */
function finurlig_widget_admin_form() {
  $form = array(
    '#tree' => TRUE,
  );

  $options_colors = array(
    'default' => t('Red'),
    'blue' => t('Blue'),
    'green' => t('Green'),
    'orange' => t('Orange'),
    'turquoise' => t('Turquoise'),
  );

  $default = variable_get('fff_widget', array());

  // Widget type (interactive is an block)
  $form['fff_widget']['type'] = array(
    '#type' => 'select',
    '#title' => t('Widget type'),
    '#description' => t('If you select "interactive" will generate a block that you have to inseret on you page, while "slide in" will... well slide in.'),
    '#options' => array(
      'interactive' => t('Interactive'),
      'slidein' => t('Slide in'),
    ),
    '#default_value' => isset($default['type']) ? $default['type'] : array('interactive'),
  );

  /**
   *  @todo: If slide-in widget, where to slide from ?.
   */

  // Style, type and color.
  $form['fff_widget']['style'] = array(
    '#type' => 'fieldset',
    '#title' => t('Look and feel'),
  );

  $form['fff_widget']['style']['type'] = array(
    '#type' => 'select',
    '#title' => t('Display type'),
    '#description' => t('The amount of information to display from the web-service.'),
    '#options' => array(
      'none' => t('None'),
      'minimal' => t('Minimal'),
      'normal' => t('Normal'),
      'full' => t('Full'),
    ),
    '#default_value' => isset($default['style']['type']) ? $default['style']['type'] : array('normal'),
  );

  $form['fff_widget']['style']['color'] = array(
    '#type' => 'select',
    '#title' => t('Color'),
    '#description' => t('Select the color to give the widget graphics.'),
    '#options' => $options_colors,
    '#default_value' => isset($default['style']['color']) ? $default['style']['color'] : array('default'),
  );


  // Extra options.
  $form['fff_widget']['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Widget options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Target, CSS id to use.
  $form['fff_widget']['options']['target'] = array(
    '#type' => 'textfield',
    '#title' => t('Widget ID'),
    '#description' => t('The CSS ID to give the widget, mostly used if you want to modify default styling.'),
    '#default_value' => isset($default['options']['target']) ? $default['options']['target'] : 'firnulig-widget',
  );

  // Reload button
  $form['fff_widget']['options']['reload'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable reload'),
    '#description' => t('Display the reload button.'),
    '#default_value' => isset($default['options']['reload']) ? $default['options']['reload'] : TRUE,
  );

  // Add fact button
  $form['fff_widget']['options']['create'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable create fact'),
    '#description' => t('Display the create fact link.'),
    '#default_value' => isset($default['options']['create']) ? $default['options']['create'] : FALSE,
  );

  // GA tracking
  $form['fff_widget']['options']['tracking'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Google Analytics tracking'),
    '#description' => t('We recommend that you allow us to use Google Analytics to track usage of your service. This will justify the costs of running the service.'),
    '#default_value' => isset($default['options']['tracking']) ? $default['options']['tracking'] : TRUE,
  );

  return system_settings_form($form);
}
