; ModuleID = 'printf_stub_link.validation.rob'
source_filename = "printf_stub_link.validation.rob"
target datalayout = "e-m:e-p:32:32-Fi8-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "thumbv7m-none-eabi"

@calls = local_unnamed_addr global i32 0
@conststr = private unnamed_addr constant [9 x i8] c"value=%d\0A"

declare i32 @printf(ptr, ptr, i32 zeroext, i32 zeroext) local_unnamed_addr #0

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(readwrite, argmem: none, inaccessiblemem: none)
define i32 @next() local_unnamed_addr #1 {
body:
  %calls = load i32, ptr @calls, align 4
  %binop = add i32 %calls, 1
  store i32 %binop, ptr @calls, align 4
  %binop2 = add i32 %calls, 3
  ret i32 %binop2
}

define i32 @main() local_unnamed_addr #0 {
body:
  %__c2rob_printf_pack_0 = alloca [3 x i64], align 8
  %calls.i = load i32, ptr @calls, align 4
  %binop.i = add i32 %calls.i, 1
  store i32 %binop.i, ptr @calls, align 4
  %binop2.i = add i32 %calls.i, 3
  %sext = sext i32 %binop2.i to i64
  store i64 1, ptr %__c2rob_printf_pack_0, align 8
  %elem2 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 8
  store i64 1, ptr %elem2, align 8
  %elem3 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 16
  store i64 %sext, ptr %elem3, align 8
  %0 = call i32 @printf(ptr nonnull @conststr, ptr nonnull %__c2rob_printf_pack_0, i32 zeroext 9, i32 zeroext 3)
  %calls = load i32, ptr @calls, align 4
  ret i32 %calls
}

attributes #0 = { "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }
attributes #1 = { mustprogress nofree norecurse nosync nounwind willreturn memory(readwrite, argmem: none, inaccessiblemem: none) "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }

!llvm.module.flags = !{!0}

!0 = !{i32 7, !"frame-pointer", i32 2}
