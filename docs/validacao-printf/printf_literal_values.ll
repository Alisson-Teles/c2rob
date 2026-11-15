; ModuleID = 'printf_literal_values.validation.rob'
source_filename = "printf_literal_values.validation.rob"
target datalayout = "e-m:e-p:32:32-Fi8-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "thumbv7m-none-eabi"

@conststr = private unnamed_addr constant [29 x i8] c"a\C3\A7\C3\A3o: %.17g %.17g %.17g %c\0A"

declare i32 @printf(ptr, ptr, i32 zeroext, i32 zeroext) local_unnamed_addr #0

define noundef i32 @main() local_unnamed_addr #0 {
body:
  %__c2rob_printf_pack_0 = alloca [9 x i64], align 8
  store i64 4, ptr %__c2rob_printf_pack_0, align 8
  %elem6 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 8
  store i64 5, ptr %elem6, align 8
  %elem7 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 16
  store i64 4593560419855049054, ptr %elem7, align 8
  %elem8 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 24
  store i64 5, ptr %elem8, align 8
  %elem9 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 32
  store i64 4593560419993387008, ptr %elem9, align 8
  %elem10 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 40
  store i64 5, ptr %elem10, align 8
  %elem11 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 48
  store i64 4553983648201703424, ptr %elem11, align 8
  %elem12 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 56
  store i64 1, ptr %elem12, align 8
  %elem13 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 64
  store i64 90, ptr %elem13, align 8
  %0 = call i32 @printf(ptr nonnull @conststr, ptr nonnull %__c2rob_printf_pack_0, i32 zeroext 29, i32 zeroext 9)
  ret i32 0
}

attributes #0 = { "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }

!llvm.module.flags = !{!0}

!0 = !{i32 7, !"frame-pointer", i32 2}
