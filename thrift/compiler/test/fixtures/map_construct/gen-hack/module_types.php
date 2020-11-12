<?hh // strict
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * Original thrift enum:-
 * TestEnum
 */
enum TestEnum: int {
  UNKNOWN = 0;
  VALUE1 = 1;
  VALUE2 = 2;
}

/**
 * Original thrift struct:-
 * Foo
 */
class Foo implements \IThriftStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'a',
      'type' => \TType::LST,
      'etype' => \TType::STRING,
      'elem' => shape(
        'type' => \TType::STRING,
      ),
      'format' => 'collection',
    ),
    2 => shape(
      'var' => 'b',
      'type' => \TType::MAP,
      'ktype' => \TType::STRING,
      'vtype' => \TType::LST,
      'key' => shape(
        'type' => \TType::STRING,
      ),
      'val' => shape(
        'type' => \TType::LST,
        'etype' => \TType::SET,
        'elem' => shape(
          'type' => \TType::SET,
          'etype' => \TType::I32,
          'elem' => shape(
            'type' => \TType::I32,
          ),
          'format' => 'collection',
        ),
        'format' => 'collection',
      ),
      'format' => 'collection',
    ),
    3 => shape(
      'var' => 'c',
      'type' => \TType::I64,
    ),
    4 => shape(
      'var' => 'd',
      'type' => \TType::BOOL,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'a' => 1,
    'b' => 2,
    'c' => 3,
    'd' => 4,
  ];

  const type TConstructorShape = shape(
    ?'a' => Vector<string>,
    ?'b' => ?Map<string, Vector<Set<int>>>,
    ?'c' => int,
    ?'d' => bool,
  );

  const int STRUCTURAL_ID = 3946809642153193229;
  /**
   * Original thrift field:-
   * 1: list<string> a
   */
  public Vector<string> $a;
  /**
   * Original thrift field:-
   * 2: map<string, list<set<i32>>> b
   */
  public ?Map<string, Vector<Set<int>>> $b;
  /**
   * Original thrift field:-
   * 3: i64 c
   */
  public int $c;
  /**
   * Original thrift field:-
   * 4: bool d
   */
  public bool $d;

  <<__Rx>>
  public function __construct(@KeyedContainer<string, mixed> $vals = dict[]) {
    /* HH_FIXME[4110] previously hidden by unsafe */
    $this->a = idx($vals, 'a') ?? Vector {};
    if (idx($vals, 'b') !== null) {
      /* HH_FIXME[4110] previously hidden by unsafe */
      $this->b = idx($vals, 'b');
    }
    $this->c = (int)idx($vals, 'c') ?? 7;
    $this->d = (bool)idx($vals, 'd') ?? false;
  }

  <<__Rx>>
  public static function withDefaultValues(): this {
    return new static();
  }

  <<__Rx>>
  public static function fromShape(self::TConstructorShape $shape): this {
    return new static(
      Map {
        'a' => Shapes::idx($shape, 'a'),
        'b' => Shapes::idx($shape, 'b'),
        'c' => Shapes::idx($shape, 'c'),
        'd' => Shapes::idx($shape, 'd'),
      },
    );
  }

  <<__Rx>>
  public static function fromMap_DEPRECATED(@KeyedContainer<string, mixed> $map = dict[]): this {
    return new static($map);
  }

  public function getName(): string {
    return 'Foo';
  }

  public static function getAllStructuredAnnotations(): \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
        'a' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
        'b' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
        'c' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
        'd' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
      ],
    );
  }

  public static function getAnnotations(): darray<string, mixed> {
    return darray[
    ];
  }

}

enum TestUnionEnum: int {
  _EMPTY_ = 0;
  string_field = 1;
  int_field = 2;
  enum_field = 3;
  foo_struct = 4;
}

/**
 * Original thrift struct:-
 * TestUnion
 */
class TestUnion implements \IThriftStruct, \IThriftUnion<TestUnionEnum> {
  use \ThriftUnionSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'string_field',
      'union' => true,
      'type' => \TType::STRING,
    ),
    2 => shape(
      'var' => 'int_field',
      'union' => true,
      'type' => \TType::I32,
    ),
    3 => shape(
      'var' => 'enum_field',
      'union' => true,
      'type' => \TType::I32,
      'enum' => TestEnum::class,
    ),
    4 => shape(
      'var' => 'foo_struct',
      'union' => true,
      'type' => \TType::STRUCT,
      'class' => Foo::class,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'string_field' => 1,
    'int_field' => 2,
    'enum_field' => 3,
    'foo_struct' => 4,
  ];

  const type TConstructorShape = shape(
    ?'string_field' => ?string,
    ?'int_field' => ?int,
    ?'enum_field' => ?TestEnum,
    ?'foo_struct' => ?Foo,
  );

  const int STRUCTURAL_ID = 1329962823516941134;
  /**
   * Original thrift field:-
   * 1: string string_field
   */
  public ?string $string_field;
  /**
   * Original thrift field:-
   * 2: i32 int_field
   */
  public ?int $int_field;
  /**
   * Original thrift field:-
   * 3: enum module.TestEnum enum_field
   */
  public ?TestEnum $enum_field;
  /**
   * Original thrift field:-
   * 4: struct module.Foo foo_struct
   */
  public ?Foo $foo_struct;
  protected TestUnionEnum $_type = TestUnionEnum::_EMPTY_;

  <<__Rx>>
  public function __construct(@KeyedContainer<string, mixed> $vals = dict[]) {
    $this->_type = TestUnionEnum::_EMPTY_;
    if (idx($vals, 'string_field') !== null) {
      $this->string_field = (string)$vals['string_field'];
      $this->_type = TestUnionEnum::string_field;
    }
    if (idx($vals, 'int_field') !== null) {
      $this->int_field = (int)$vals['int_field'];
      $this->_type = TestUnionEnum::int_field;
    }
    if (idx($vals, 'enum_field') !== null) {
      /* HH_FIXME[4110] previously hidden by unsafe */
      $this->enum_field = $vals['enum_field'];
      $this->_type = TestUnionEnum::enum_field;
    }
    if (idx($vals, 'foo_struct') !== null) {
      /* HH_FIXME[4110] previously hidden by unsafe */
      $this->foo_struct = $vals['foo_struct'];
      $this->_type = TestUnionEnum::foo_struct;
    }
  }

  <<__Rx>>
  public static function withDefaultValues(): this {
    return new static();
  }

  <<__Rx>>
  public static function fromShape(self::TConstructorShape $shape): this {
    return new static(
      Map {
        'string_field' => Shapes::idx($shape, 'string_field'),
        'int_field' => Shapes::idx($shape, 'int_field'),
        'enum_field' => Shapes::idx($shape, 'enum_field'),
        'foo_struct' => Shapes::idx($shape, 'foo_struct'),
      },
    );
  }

  <<__Rx>>
  public static function fromMap_DEPRECATED(@KeyedContainer<string, mixed> $map = dict[]): this {
    return new static($map);
  }

  public function getName(): string {
    return 'TestUnion';
  }

  public function getType(): TestUnionEnum {
    return $this->_type;
  }

  public function reset(): void {
    switch ($this->_type) {
      case TestUnionEnum::string_field:
        $this->string_field = null;
        break;
      case TestUnionEnum::int_field:
        $this->int_field = null;
        break;
      case TestUnionEnum::enum_field:
        $this->enum_field = null;
        break;
      case TestUnionEnum::foo_struct:
        $this->foo_struct = null;
        break;
      case TestUnionEnum::_EMPTY_:
        break;
    }
    $this->_type = TestUnionEnum::_EMPTY_;
}

  public function set_string_field(string $string_field): this {
    $this->reset();
    $this->_type = TestUnionEnum::string_field;
    $this->string_field = $string_field;
    return $this;
  }

  public function get_string_field(): string {
    invariant(
      $this->_type === TestUnionEnum::string_field,
      'get_string_field called on an instance of TestUnion whose current type is %s',
      (string)$this->_type,
    );
    return $this->string_field as nonnull;
  }

  public function set_int_field(int $int_field): this {
    $this->reset();
    $this->_type = TestUnionEnum::int_field;
    $this->int_field = $int_field;
    return $this;
  }

  public function get_int_field(): int {
    invariant(
      $this->_type === TestUnionEnum::int_field,
      'get_int_field called on an instance of TestUnion whose current type is %s',
      (string)$this->_type,
    );
    return $this->int_field as nonnull;
  }

  public function set_enum_field(TestEnum $enum_field): this {
    $this->reset();
    $this->_type = TestUnionEnum::enum_field;
    $this->enum_field = $enum_field;
    return $this;
  }

  public function get_enum_field(): TestEnum {
    invariant(
      $this->_type === TestUnionEnum::enum_field,
      'get_enum_field called on an instance of TestUnion whose current type is %s',
      (string)$this->_type,
    );
    return $this->enum_field as nonnull;
  }

  public function set_foo_struct(Foo $foo_struct): this {
    $this->reset();
    $this->_type = TestUnionEnum::foo_struct;
    $this->foo_struct = $foo_struct;
    return $this;
  }

  public function get_foo_struct(): Foo {
    invariant(
      $this->_type === TestUnionEnum::foo_struct,
      'get_foo_struct called on an instance of TestUnion whose current type is %s',
      (string)$this->_type,
    );
    return $this->foo_struct as nonnull;
  }

  public static function getAllStructuredAnnotations(): \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
        'string_field' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
        'int_field' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
        'enum_field' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
        'foo_struct' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
      ],
    );
  }

  public static function getAnnotations(): darray<string, mixed> {
    return darray[
    ];
  }

}

/**
 * Original thrift exception:-
 * Baz
 */
class Baz extends \TException implements \IThriftStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'message',
      'type' => \TType::STRING,
    ),
    2 => shape(
      'var' => 'some_field',
      'type' => \TType::STRUCT,
      'class' => Foo::class,
    ),
    3 => shape(
      'var' => 'some_container',
      'type' => \TType::SET,
      'etype' => \TType::STRING,
      'elem' => shape(
        'type' => \TType::STRING,
      ),
      'format' => 'collection',
    ),
    4 => shape(
      'var' => 'code',
      'type' => \TType::I32,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'message' => 1,
    'some_field' => 2,
    'some_container' => 3,
    'code' => 4,
  ];

  const type TConstructorShape = shape(
    ?'message' => string,
    ?'some_field' => ?Foo,
    ?'some_container' => Set<string>,
    ?'code' => int,
  );

  const int STRUCTURAL_ID = 1663976252517274137;
  /**
   * Original thrift field:-
   * 1: string message
   */
  public string $message;
  /**
   * Original thrift field:-
   * 2: struct module.Foo some_field
   */
  public ?Foo $some_field;
  /**
   * Original thrift field:-
   * 3: set<string> some_container
   */
  public Set<string> $some_container;
  /**
   * Original thrift field:-
   * 4: i32 code
   */
  public int $code;

  <<__Rx>>
  public function __construct(@KeyedContainer<string, mixed> $vals = dict[]) {
    parent::__construct();
    $this->message = (string)idx($vals, 'message') ?? '';
    /* HH_FIXME[4110] previously hidden by unsafe */
    $this->some_field = idx($vals, 'some_field');
    /* HH_FIXME[4110] previously hidden by unsafe */
    $this->some_container = idx($vals, 'some_container') ?? Set {};
    $this->code = (int)idx($vals, 'code') ?? 0;
  }

  <<__Rx>>
  public static function withDefaultValues(): this {
    return new static();
  }

  <<__Rx>>
  public static function fromShape(self::TConstructorShape $shape): this {
    return new static(
      Map {
        'message' => Shapes::idx($shape, 'message'),
        'some_field' => Shapes::idx($shape, 'some_field'),
        'some_container' => Shapes::idx($shape, 'some_container'),
        'code' => Shapes::idx($shape, 'code'),
      },
    );
  }

  <<__Rx>>
  public static function fromMap_DEPRECATED(@KeyedContainer<string, mixed> $map = dict[]): this {
    return new static($map);
  }

  public function getName(): string {
    return 'Baz';
  }

  public static function getAllStructuredAnnotations(): \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
        'message' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
        'some_field' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
        'some_container' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
        'code' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
      ],
    );
  }

  public static function getAnnotations(): darray<string, mixed> {
    return darray[
    ];
  }

}

/**
 * Original thrift exception:-
 * OptBaz
 */
class OptBaz extends \TException implements \IThriftStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'message',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'message' => 1,
  ];

  const type TConstructorShape = shape(
    ?'message' => ?string,
  );

  const int STRUCTURAL_ID = 546500496397478593;
  /**
   * Original thrift field:-
   * 1: string message
   */
  public string $message;

  <<__Rx>>
  public function __construct(@KeyedContainer<string, mixed> $vals = dict[]) {
    parent::__construct();
    $this->message = (string)idx($vals, 'message') ?? '';
  }

  <<__Rx>>
  public static function withDefaultValues(): this {
    return new static();
  }

  <<__Rx>>
  public static function fromShape(self::TConstructorShape $shape): this {
    return new static(
      Map {
        'message' => Shapes::idx($shape, 'message'),
      },
    );
  }

  <<__Rx>>
  public static function fromMap_DEPRECATED(@KeyedContainer<string, mixed> $map = dict[]): this {
    return new static($map);
  }

  public function getName(): string {
    return 'OptBaz';
  }

  public static function getAllStructuredAnnotations(): \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
        'message' => shape(
          'field' => dict[],
          'type' => dict[],
        ),
      ],
    );
  }

  public static function getAnnotations(): darray<string, mixed> {
    return darray[
    ];
  }

}

