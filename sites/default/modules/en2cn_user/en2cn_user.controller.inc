<?php

/**
 * Controller for adding and reducing en2cn user's contribution points.
 *
 * The default loader, which we extend, handles load() already. We only
 * need to add inserting, deleting, adding and reducing points functions.
 */
class En2CnUserController extends DrupalDefaultEntityController {

  public function insert($account) {
    try {
      // If there is no record whose uid is $account->uid, create it
      // or do nothing
      db_merge('en2cn_user')
        ->key(array('uid' => $account->uid))
        ->insertFields(array(
          'uid' => $account->uid,
          'points' => 0,
      ))->execute();

      // If there is no exception, just return true
      return TRUE;
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

      return TRUE;
    }
    catch (Exception $e) {
      watchdog_exception('en2cn_user', $e, NULL, WATCHDOG_ERROR);
      return FALSE;
    }
  }
}
