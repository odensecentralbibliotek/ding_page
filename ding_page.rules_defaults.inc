<?php
/**
 * @file
 * ding_page.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ding_page_default_rules_configuration() {
  $items = array();
  $items['rules_ding_page_node_update'] = entity_import('rules_config', '{ "rules_ding_page_node_update" : {
      "LABEL" : "Ding page node update",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "ding", "node" ],
      "REQUIRES" : [ "rules", "cache_actions" ],
      "ON" : [ "node_update", "node_delete", "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "ding_page" : "ding_page" } }
          }
        }
      ],
      "DO" : [
        { "cache_actions_action_clear_panels_pane_cache" : { "panes" : { "value" : {
                "50bf11a45311a" : "50bf11a45311a",
                "50bf11a45d23b" : "50bf11a45d23b",
                "50bf11a46e048" : "50bf11a46e048",
                "50bf11a4783d2" : "50bf11a4783d2",
                "50e6de8f5cb22" : "50e6de8f5cb22"
              }
            }
          }
        }
      ]
    }
  }');
  return $items;
}
