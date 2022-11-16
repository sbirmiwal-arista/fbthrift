/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.patch;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import com.google.common.collect.*;
import java.util.*;
import javax.annotation.Nullable;
import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@com.facebook.swift.codec.ThriftStruct(value="MyUnionFieldPatch", builder=MyUnionFieldPatch.Builder.class)
public final class MyUnionFieldPatch implements com.facebook.thrift.payload.ThriftSerializable {

    @ThriftConstructor
    public MyUnionFieldPatch(
        @com.facebook.swift.codec.ThriftField(value=1, name="option1", requiredness=Requiredness.TERSE) final com.facebook.thrift.op.StringPatch option1,
        @com.facebook.swift.codec.ThriftField(value=2, name="option2", requiredness=Requiredness.TERSE) final com.facebook.thrift.op.I32Patch option2,
        @com.facebook.swift.codec.ThriftField(value=3, name="option3", requiredness=Requiredness.TERSE) final test.fixtures.patch.InnerUnionPatch option3
    ) {
        this.option1 = option1;
        this.option2 = option2;
        this.option3 = option3;
    }
    
    @ThriftConstructor
    protected MyUnionFieldPatch() {
      this.option1 = com.facebook.thrift.op.StringPatch.defaultInstance();
      this.option2 = com.facebook.thrift.op.I32Patch.defaultInstance();
      this.option3 = test.fixtures.patch.InnerUnionPatch.defaultInstance();
    }
    
    public static class Builder {
    
        private com.facebook.thrift.op.StringPatch option1 = com.facebook.thrift.op.StringPatch.defaultInstance();
        private com.facebook.thrift.op.I32Patch option2 = com.facebook.thrift.op.I32Patch.defaultInstance();
        private test.fixtures.patch.InnerUnionPatch option3 = test.fixtures.patch.InnerUnionPatch.defaultInstance();
    
        @com.facebook.swift.codec.ThriftField(value=1, name="option1", requiredness=Requiredness.TERSE)
        public Builder setOption1(com.facebook.thrift.op.StringPatch option1) {
            this.option1 = option1;
            return this;
        }
    
        public com.facebook.thrift.op.StringPatch getOption1() { return option1; }
    
            @com.facebook.swift.codec.ThriftField(value=2, name="option2", requiredness=Requiredness.TERSE)
        public Builder setOption2(com.facebook.thrift.op.I32Patch option2) {
            this.option2 = option2;
            return this;
        }
    
        public com.facebook.thrift.op.I32Patch getOption2() { return option2; }
    
            @com.facebook.swift.codec.ThriftField(value=3, name="option3", requiredness=Requiredness.TERSE)
        public Builder setOption3(test.fixtures.patch.InnerUnionPatch option3) {
            this.option3 = option3;
            return this;
        }
    
        public test.fixtures.patch.InnerUnionPatch getOption3() { return option3; }
    
        public Builder() { }
        public Builder(MyUnionFieldPatch other) {
            this.option1 = other.option1;
            this.option2 = other.option2;
            this.option3 = other.option3;
        }
    
        @ThriftConstructor
        public MyUnionFieldPatch build() {
            MyUnionFieldPatch result = new MyUnionFieldPatch (
                this.option1,
                this.option2,
                this.option3
            );
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("MyUnionFieldPatch");
    private final com.facebook.thrift.op.StringPatch option1;
    public static final int _OPTION1 = 1;
    private static final TField OPTION1_FIELD_DESC = new TField("option1", TType.STRUCT, (short)1);
        private final com.facebook.thrift.op.I32Patch option2;
    public static final int _OPTION2 = 2;
    private static final TField OPTION2_FIELD_DESC = new TField("option2", TType.STRUCT, (short)2);
        private final test.fixtures.patch.InnerUnionPatch option3;
    public static final int _OPTION3 = 3;
    private static final TField OPTION3_FIELD_DESC = new TField("option3", TType.STRUCT, (short)3);
    static {
      NAMES_TO_IDS.put("option1", 1);
      THRIFT_NAMES_TO_IDS.put("option1", 1);
      FIELD_METADATA.put(1, OPTION1_FIELD_DESC);
      NAMES_TO_IDS.put("option2", 2);
      THRIFT_NAMES_TO_IDS.put("option2", 2);
      FIELD_METADATA.put(2, OPTION2_FIELD_DESC);
      NAMES_TO_IDS.put("option3", 3);
      THRIFT_NAMES_TO_IDS.put("option3", 3);
      FIELD_METADATA.put(3, OPTION3_FIELD_DESC);
      com.facebook.thrift.type.TypeRegistry.add(new com.facebook.thrift.type.Type(
        new com.facebook.thrift.type.UniversalName("test.dev/fixtures/patch/MyUnionFieldPatch"), 
        MyUnionFieldPatch.class, MyUnionFieldPatch::read0));
    }
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=1, name="option1", requiredness=Requiredness.TERSE)
    public com.facebook.thrift.op.StringPatch getOption1() { return option1; }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=2, name="option2", requiredness=Requiredness.TERSE)
    public com.facebook.thrift.op.I32Patch getOption2() { return option2; }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=3, name="option3", requiredness=Requiredness.TERSE)
    public test.fixtures.patch.InnerUnionPatch getOption3() { return option3; }
    
    @java.lang.Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("option1", option1);
        helper.add("option2", option2);
        helper.add("option3", option3);
        return helper.toString();
    }
    
    @java.lang.Override
    public boolean equals(java.lang.Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        MyUnionFieldPatch other = (MyUnionFieldPatch)o;
    
        return
            Objects.equals(option1, other.option1) &&
            Objects.equals(option2, other.option2) &&
            Objects.equals(option3, other.option3) &&
            true;
    }
    
    @java.lang.Override
    public int hashCode() {
        return Arrays.deepHashCode(new java.lang.Object[] {
            option1,
            option2,
            option3
        });
    }
    
    
    public static com.facebook.thrift.payload.Reader<MyUnionFieldPatch> asReader() {
      return MyUnionFieldPatch::read0;
    }
    
    public static MyUnionFieldPatch read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(MyUnionFieldPatch.NAMES_TO_IDS, MyUnionFieldPatch.THRIFT_NAMES_TO_IDS, MyUnionFieldPatch.FIELD_METADATA);
      MyUnionFieldPatch.Builder builder = new MyUnionFieldPatch.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _OPTION1:
          if (__field.type == TType.STRUCT) {
            com.facebook.thrift.op.StringPatch option1 = com.facebook.thrift.op.StringPatch.read0(oprot);
            builder.setOption1(option1);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _OPTION2:
          if (__field.type == TType.STRUCT) {
            com.facebook.thrift.op.I32Patch option2 = com.facebook.thrift.op.I32Patch.read0(oprot);
            builder.setOption2(option2);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _OPTION3:
          if (__field.type == TType.STRUCT) {
            test.fixtures.patch.InnerUnionPatch option3 = test.fixtures.patch.InnerUnionPatch.read0(oprot);
            builder.setOption3(option3);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }
    
    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      int structStart = 0;
      int pos = 0;
      com.facebook.thrift.protocol.ByteBufTProtocol p = (com.facebook.thrift.protocol.ByteBufTProtocol) oprot;
      java.util.Objects.requireNonNull(option1, "option1 must not be null");
      structStart = p.mark();
        oprot.writeFieldBegin(OPTION1_FIELD_DESC);
        pos = p.mark();
        this.option1.write0(oprot);
        if (p.mark() - pos > p.getEmptyStructSize()) {
          p.writeFieldEnd();    
        } else {
          p.rollback(structStart);
        }    
      java.util.Objects.requireNonNull(option2, "option2 must not be null");
      structStart = p.mark();
        oprot.writeFieldBegin(OPTION2_FIELD_DESC);
        pos = p.mark();
        this.option2.write0(oprot);
        if (p.mark() - pos > p.getEmptyStructSize()) {
          p.writeFieldEnd();    
        } else {
          p.rollback(structStart);
        }    
      java.util.Objects.requireNonNull(option3, "option3 must not be null");
      structStart = p.mark();
        oprot.writeFieldBegin(OPTION3_FIELD_DESC);
        pos = p.mark();
        this.option3.write0(oprot);
        if (p.mark() - pos > p.getEmptyStructSize()) {
          p.writeFieldEnd();    
        } else {
          p.rollback(structStart);
        }    
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
    private static class _MyUnionFieldPatchLazy {
        private static final MyUnionFieldPatch _DEFAULT = new MyUnionFieldPatch.Builder().build();
    }
    
    public static MyUnionFieldPatch defaultInstance() {
        return  _MyUnionFieldPatchLazy._DEFAULT;
    }
}
