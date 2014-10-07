<?php

/**
 * Common mappings for the Drupal 6 node migrations.
 */
abstract class ExampleNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_legacy_nid', 'nid')
         ->description('We have a common field to save the D6 nid');
  }
}

class LineagePageMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
}

class DharmaQuoteMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
}

class AboutPageMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
}

class ActivitiesPageMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
}

class ResourcesPageMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
}

class SupportKCCPageMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
}

class ContactUsPageMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
}

class PolicyMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    $attachment_fields = array(
        'attachments_filename' => t('field_file_attachments'),
    );
    $this->sourceFields = array_merge($this->sourceFields, $attachment_fields);
    parent::__construct($arguments);
// Map the file field to the new document field, base this on the Files migration
// to map the files to the imported files table.
    $this->addFieldMapping('field_document', 'field_file_attachments')
         ->sourceMigration('DefaultFiles');
    $this->addFieldMapping('field_document:file_class')
         ->defaultValue('MigrateFileFid');
  }
  protected function query() {
    $query = parent::query();
    return $query;
  }
  public function prepareRow(&$current_row) {
    parent::prepareRow($current_row);
    $query = Database::getConnection('default', $this->sourceConnection)
       ->select('upload', 'up')->condition('up.vid', $current_row->vid, '=')
       ->fields('up', array('fid'));
    $result = $query->execute();
    foreach ($result as $row) {
      $current_row->field_file_attachments[] = $row->fid;
    }
  }
}

class ReportPageMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    $attachment_fields = array(
        'attachments_filename' => t('field_minute_file'),
    );
    $this->sourceFields = array_merge($this->sourceFields, $attachment_fields);
    parent::__construct($arguments);
// Map the file field to the new document field, base this on the Files migration
// to map the files to the imported files table.
    $this->addFieldMapping('field_document', 'field_minute_file')
         ->sourceMigration('DefaultFiles');
    $this->addFieldMapping('field_document:file_class')
         ->defaultValue('MigrateFileFid');
  }
  protected function query() {
    $query = parent::query();
    return $query;
  }
  public function prepareRow(&$current_row) {
    parent::prepareRow($current_row);
    $query = Database::getConnection('default', $this->sourceConnection)
       ->select('upload', 'up')->condition('up.vid', $current_row->vid, '=')
       ->fields('up', array('fid'));
    $result = $query->execute();
    foreach ($result as $row) {
      $current_row->field_minute_file[] = $row->fid;
    }
  }
}

class RetreatCommitteePageMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    $attachment_fields = array(
        'attachments_filename' => t('field_file_attachments'),
    );
    $this->sourceFields = array_merge($this->sourceFields, $attachment_fields);
    parent::__construct($arguments);
// Map the file field to the new document field, base this on the Files migration
// to map the files to the imported files table.
    $this->addFieldMapping('field_document', 'field_file_attachments')
         ->sourceMigration('DefaultFiles');
    $this->addFieldMapping('field_document:file_class')
         ->defaultValue('MigrateFileFid');
  }
  protected function query() {
    $query = parent::query();
    return $query;
  }
  public function prepareRow(&$current_row) {
    parent::prepareRow($current_row);
    $query = Database::getConnection('default', $this->sourceConnection)
       ->select('upload', 'up')->condition('up.vid', $current_row->vid, '=')
       ->fields('up', array('fid'));
    $result = $query->execute();
    foreach ($result as $row) {
      $current_row->field_file_attachments[] = $row->fid;
    }
  }
}

class UpcomingEventMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->addFieldMapping('field_time', 'field_ue_date');
    $this->addFieldMapping('field_time:to', 'field_ue_date:value2');
    $this->addFieldMapping('field_time:timezone', 'field_ue_date:timezone');
  }
}

class RetreatMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->addFieldMapping('field_time', 'field_retreat_date');
    $this->addFieldMapping('field_time:to', 'field_retreat_date:value2');
    $this->addFieldMapping('field_time:timezone', 'field_retreat_date:timezone');
    $this->addFieldMapping('field_location', 'field_retreat_place');
    $this->addFieldMapping('field_event_leader', 'field_retreat_leader');
  }
}
