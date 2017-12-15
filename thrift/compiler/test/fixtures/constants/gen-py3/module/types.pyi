#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

import thrift.py3.types
import thrift.py3.exceptions
from thrift.py3.types import NOTSET, NOTSETTYPE
from thrift.py3.serializer import Protocol
import typing as _typing

import sys
import itertools
import enum as __enum


class EmptyEnum(__enum.Enum, _typing.SupportsInt):
    value: int
    def __int__(self) -> int: ...


class City(__enum.Enum, _typing.SupportsInt):
    NYC = ...
    MPK = ...
    SEA = ...
    LON = ...
    value: int
    def __int__(self) -> int: ...


class Company(__enum.Enum, _typing.SupportsInt):
    FACEBOOK = ...
    WHATSAPP = ...
    OCULUS = ...
    INSTAGRAM = ...
    value: int
    def __int__(self) -> int: ...


class Internship(thrift.py3.types.Struct):
    def __init__(
        self, *,
        weeks: int,
        title: str=None,
        employer: Company=None
    ) -> None: ...

    def __call__(
        self, *,
        weeks: _typing.Union[int, NOTSETTYPE]=NOTSET,
        title: _typing.Union[str, NOTSETTYPE, None]=NOTSET,
        employer: _typing.Union[Company, NOTSETTYPE, None]=NOTSET
    ) -> Internship: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['Internship'], bytes]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'Internship') -> bool: ...

    @property
    def weeks(self) -> int: ...
    @property
    def title(self) -> str: ...
    @property
    def employer(self) -> _typing.Optional[Company]: ...


class UnEnumStruct(thrift.py3.types.Struct):
    def __init__(
        self, *,
        city: City=None
    ) -> None: ...

    def __call__(
        self, *,
        city: _typing.Union[City, NOTSETTYPE, None]=NOTSET
    ) -> UnEnumStruct: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['UnEnumStruct'], bytes]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'UnEnumStruct') -> bool: ...

    @property
    def city(self) -> City: ...


class Range(thrift.py3.types.Struct):
    def __init__(
        self, *,
        min: int,
        max: int
    ) -> None: ...

    def __call__(
        self, *,
        min: _typing.Union[int, NOTSETTYPE]=NOTSET,
        max: _typing.Union[int, NOTSETTYPE]=NOTSET
    ) -> Range: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['Range'], bytes]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'Range') -> bool: ...

    @property
    def min(self) -> int: ...
    @property
    def max(self) -> int: ...


class struct1(thrift.py3.types.Struct):
    def __init__(
        self, *,
        a: int=None,
        b: str=None
    ) -> None: ...

    def __call__(
        self, *,
        a: _typing.Union[int, NOTSETTYPE, None]=NOTSET,
        b: _typing.Union[str, NOTSETTYPE, None]=NOTSET
    ) -> struct1: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['struct1'], bytes]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'struct1') -> bool: ...

    @property
    def a(self) -> int: ...
    @property
    def b(self) -> str: ...


class struct2(thrift.py3.types.Struct):
    def __init__(
        self, *,
        a: int=None,
        b: str=None,
        c: 'struct1'=None,
        d: _typing.Sequence[int]=None
    ) -> None: ...

    def __call__(
        self, *,
        a: _typing.Union[int, NOTSETTYPE, None]=NOTSET,
        b: _typing.Union[str, NOTSETTYPE, None]=NOTSET,
        c: _typing.Union['struct1', NOTSETTYPE, None]=NOTSET,
        d: _typing.Union[_typing.Sequence[int], NOTSETTYPE, None]=NOTSET
    ) -> struct2: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['struct2'], bytes]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'struct2') -> bool: ...

    @property
    def a(self) -> int: ...
    @property
    def b(self) -> str: ...
    @property
    def c(self) -> 'struct1': ...
    @property
    def d(self) -> _typing.Sequence[int]: ...


class struct3(thrift.py3.types.Struct):
    def __init__(
        self, *,
        a: str=None,
        b: int=None,
        c: 'struct2'=None
    ) -> None: ...

    def __call__(
        self, *,
        a: _typing.Union[str, NOTSETTYPE, None]=NOTSET,
        b: _typing.Union[int, NOTSETTYPE, None]=NOTSET,
        c: _typing.Union['struct2', NOTSETTYPE, None]=NOTSET
    ) -> struct3: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['struct3'], bytes]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'struct3') -> bool: ...

    @property
    def a(self) -> str: ...
    @property
    def b(self) -> int: ...
    @property
    def c(self) -> 'struct2': ...


class union1Type(__enum.Enum):
    EMPTY = ...
    i = ...
    d = ...
    value: int


class union1(thrift.py3.types.Union):
    def __init__(
        self, *,
        i: int=None,
        d: float=None
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'union1') -> bool: ...

    @property
    def i(self) -> int: ...
    @property
    def d(self) -> float: ...
    @staticmethod
    def fromValue(value: _typing.Union[int, float]) -> union1: ...
    @property
    def value(self) -> _typing.Union[int, float]: ...
    @property
    def type(self) -> union1Type: ...
    def get_type(self) -> union1Type: ...


class union2Type(__enum.Enum):
    EMPTY = ...
    i = ...
    d = ...
    s = ...
    u = ...
    value: int


class union2(thrift.py3.types.Union):
    def __init__(
        self, *,
        i: int=None,
        d: float=None,
        s: 'struct1'=None,
        u: 'union1'=None
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'union2') -> bool: ...

    @property
    def i(self) -> int: ...
    @property
    def d(self) -> float: ...
    @property
    def s(self) -> 'struct1': ...
    @property
    def u(self) -> 'union1': ...
    @staticmethod
    def fromValue(value: _typing.Union[int, float, 'struct1', 'union1']) -> union2: ...
    @property
    def value(self) -> _typing.Union[int, float, 'struct1', 'union1']: ...
    @property
    def type(self) -> union2Type: ...
    def get_type(self) -> union2Type: ...


_List__i32T = _typing.TypeVar('_List__i32T', bound=_typing.Sequence[int])


class List__i32(_typing.Sequence[int]):
    def __init__(self, items: _typing.Sequence[int]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def count(self, item: int) -> int: ...
    def __add__(self, other: _typing.Sequence[int]) -> 'List__i32': ...
    def __radd__(self, other: _List__i32T) -> _List__i32T: ...
    def __reversed__(self) -> _typing.Iterator[int]: ...
    def __iter__(self) -> _typing.Iterator[int]: ...


class Map__string_i32(_typing.Mapping[str, int]):
    def __init__(self, items: _typing.Mapping[str, int]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __getitem__(self, key: str) -> int: ...
    def __iter__(self) -> _typing.Iterator[str]: ...


_List__Map__string_i32T = _typing.TypeVar('_List__Map__string_i32T', bound=_typing.Sequence[_typing.Mapping[str, int]])


class List__Map__string_i32(_typing.Sequence[_typing.Mapping[str, int]]):
    def __init__(self, items: _typing.Sequence[_typing.Mapping[str, int]]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def count(self, item: _typing.Mapping[str, int]) -> int: ...
    def __add__(self, other: _typing.Sequence[_typing.Mapping[str, int]]) -> 'List__Map__string_i32': ...
    def __radd__(self, other: _List__Map__string_i32T) -> _List__Map__string_i32T: ...
    def __reversed__(self) -> _typing.Iterator[_typing.Mapping[str, int]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Mapping[str, int]]: ...


_List__RangeT = _typing.TypeVar('_List__RangeT', bound=_typing.Sequence['Range'])


class List__Range(_typing.Sequence['Range']):
    def __init__(self, items: _typing.Sequence['Range']=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def count(self, item: 'Range') -> int: ...
    def __add__(self, other: _typing.Sequence['Range']) -> 'List__Range': ...
    def __radd__(self, other: _List__RangeT) -> _List__RangeT: ...
    def __reversed__(self) -> _typing.Iterator['Range']: ...
    def __iter__(self) -> _typing.Iterator['Range']: ...


_List__InternshipT = _typing.TypeVar('_List__InternshipT', bound=_typing.Sequence['Internship'])


class List__Internship(_typing.Sequence['Internship']):
    def __init__(self, items: _typing.Sequence['Internship']=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def count(self, item: 'Internship') -> int: ...
    def __add__(self, other: _typing.Sequence['Internship']) -> 'List__Internship': ...
    def __radd__(self, other: _List__InternshipT) -> _List__InternshipT: ...
    def __reversed__(self) -> _typing.Iterator['Internship']: ...
    def __iter__(self) -> _typing.Iterator['Internship']: ...


_List__stringT = _typing.TypeVar('_List__stringT', bound=_typing.Sequence[str])


class List__string(_typing.Sequence[str]):
    def __init__(self, items: _typing.Sequence[str]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def count(self, item: str) -> int: ...
    def __add__(self, other: _typing.Sequence[str]) -> 'List__string': ...
    def __radd__(self, other: _List__stringT) -> _List__stringT: ...
    def __reversed__(self) -> _typing.Iterator[str]: ...
    def __iter__(self) -> _typing.Iterator[str]: ...


class Set__i32(_typing.AbstractSet[int]):
    def __init__(self, items: _typing.AbstractSet[int]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __lt__(self, other: _typing.AbstractSet[int]) -> bool: ...
    def __add__(self, other: _typing.AbstractSet[int]) -> 'Set__i32': ...
    def isdisjoint(self, other: _typing.AbstractSet[int]) -> bool: ...
    def union(self, other: _typing.AbstractSet[int]) -> 'Set__i32': ...
    def intersection(self, other: _typing.AbstractSet[int]) -> 'Set__i32': ...
    def difference(self, other: _typing.AbstractSet[int]) -> 'Set__i32': ...
    def symmetric_difference(self, other: _typing.AbstractSet[int]) -> 'Set__i32': ...
    def issubset(self, other: _typing.AbstractSet[int]) -> bool: ...
    def issuperset(self, other: _typing.AbstractSet[int]) -> bool: ...


class Set__string(_typing.AbstractSet[str]):
    def __init__(self, items: _typing.AbstractSet[str]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __lt__(self, other: _typing.AbstractSet[str]) -> bool: ...
    def __add__(self, other: _typing.AbstractSet[str]) -> 'Set__string': ...
    def isdisjoint(self, other: _typing.AbstractSet[str]) -> bool: ...
    def union(self, other: _typing.AbstractSet[str]) -> 'Set__string': ...
    def intersection(self, other: _typing.AbstractSet[str]) -> 'Set__string': ...
    def difference(self, other: _typing.AbstractSet[str]) -> 'Set__string': ...
    def symmetric_difference(self, other: _typing.AbstractSet[str]) -> 'Set__string': ...
    def issubset(self, other: _typing.AbstractSet[str]) -> bool: ...
    def issuperset(self, other: _typing.AbstractSet[str]) -> bool: ...


class Map__i32_i32(_typing.Mapping[int, int]):
    def __init__(self, items: _typing.Mapping[int, int]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __getitem__(self, key: int) -> int: ...
    def __iter__(self) -> _typing.Iterator[int]: ...


class Map__i32_string(_typing.Mapping[int, str]):
    def __init__(self, items: _typing.Mapping[int, str]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __getitem__(self, key: int) -> str: ...
    def __iter__(self) -> _typing.Iterator[int]: ...


class Map__string_string(_typing.Mapping[str, str]):
    def __init__(self, items: _typing.Mapping[str, str]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __getitem__(self, key: str) -> str: ...
    def __iter__(self) -> _typing.Iterator[str]: ...


myInt: int = ...
name: str = ...
states: _typing.Sequence[_typing.Mapping[str, int]] = ...
x: float = ...
y: float = ...
z: float = ...
zeroDoubleValue: float = ...
longDoubleValue: float = ...
instagram: 'Internship' = ...
kRanges: _typing.Sequence['Range'] = ...
internList: _typing.Sequence['Internship'] = ...
pod_0: 'struct1' = ...
pod_1: 'struct1' = ...
pod_2: 'struct2' = ...
pod_3: 'struct3' = ...
u_1_1: 'union1' = ...
u_1_2: 'union1' = ...
u_1_3: 'union1' = ...
u_2_1: 'union2' = ...
u_2_2: 'union2' = ...
u_2_3: 'union2' = ...
u_2_4: 'union2' = ...
u_2_5: 'union2' = ...
u_2_6: 'union2' = ...
apostrophe: str = ...
tripleApostrophe: str = ...
quotationMark: str = ...
backslash: str = ...
escaped_a: str = ...
char2ascii: _typing.Mapping[str, int] = ...
escaped_strings: _typing.Sequence[str] = ...
false_c: bool = ...
true_c: bool = ...
zero_byte: int = ...
zero16: int = ...
zero32: int = ...
zero64: int = ...
zero_dot_zero: float = ...
empty_string: str = ...
empty_int_list: _typing.Sequence[int] = ...
empty_string_list: _typing.Sequence[str] = ...
empty_int_set: _typing.AbstractSet[int] = ...
empty_string_set: _typing.AbstractSet[str] = ...
empty_int_int_map: _typing.Mapping[int, int] = ...
empty_int_string_map: _typing.Mapping[int, str] = ...
empty_string_int_map: _typing.Mapping[str, int] = ...
empty_string_string_map: _typing.Mapping[str, str] = ...
