<?php

/**
 * Controller for adding and reducing en2cn user's contribution points.
 *
 * The default loader, which we extend, handles load() already. We only
 * need to add adding and reducing.
 */
class En2CnUserController extends DrupalDefaultEntityController {

  public function insert($account) {
    try {
      db_insert('en2cn_user')
        ->fields(array(
        'points' => 0,
        'uid' => $account->uid,
      ))
      ->execute();
    }
    catch (Exception $e) {
      watchdog_exception('en2cn_user', $e, NULL, WATCHDOG_ERROR);
      return FALSE;
    }
  }

  public function delete($account) {
    try {
      db_delete('en2cn_user')
        ->condition('uid', $account->uid)
        ->execute();
    }
    catch (Exception $e) {
      watchdog_exception('en2cn_user', $e, NULL, WATCHDOG_ERROR);
      return FALSE;
    }
  }
}
