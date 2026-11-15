; ModuleID = 'printf_blocks.validation.rob'
source_filename = "printf_blocks.validation.rob"
target datalayout = "e-m:e-p:32:32-Fi8-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "thumbv7m-none-eabi"

@checks = local_unnamed_addr global i32 0
@conststr = private unnamed_addr constant [10 x i8] c"middle %d\0A"
@conststr.1 = private unnamed_addr constant [8 x i8] c"edge %d\0A"
@conststr.2 = private unnamed_addr constant [8 x i8] c"loop %d\0A"
@conststr.3 = private unnamed_addr constant [8 x i8] c"done %d\0A"
@conststr.4 = private unnamed_addr constant [14 x i8] c"checks: %d %d\0A"

declare i32 @printf(ptr, ptr, i32 zeroext, i32 zeroext) local_unnamed_addr #0

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(readwrite, argmem: none, inaccessiblemem: none)
define i32 @check(i32 returned %n) local_unnamed_addr #1 {
body:
  %checks = load i32, ptr @checks, align 4
  %binop = add i32 %checks, 1
  store i32 %binop, ptr @checks, align 4
  ret i32 %n
}

define i32 @main() local_unnamed_addr #0 {
if_cont74:
  %__c2rob_printf_pack_0 = alloca [3 x i64], align 8
  %__c2rob_printf_pack_1 = alloca [3 x i64], align 8
  %__c2rob_printf_pack_2 = alloca [3 x i64], align 8
  %__c2rob_printf_pack_3 = alloca [3 x i64], align 8
  %__c2rob_printf_pack_4 = alloca [5 x i64], align 8
  %elem12 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_1, i32 8
  %elem13 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_1, i32 16
  %elem6 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 8
  %elem7 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_0, i32 16
  store i64 1, ptr %__c2rob_printf_pack_1, align 8
  store i64 1, ptr %elem12, align 8
  store i64 1, ptr %elem13, align 8
  %0 = call i32 @printf(ptr nonnull @conststr.1, ptr nonnull %__c2rob_printf_pack_1, i32 zeroext 8, i32 zeroext 3)
  store i64 1, ptr %__c2rob_printf_pack_0, align 8
  store i64 1, ptr %elem6, align 8
  store i64 1, ptr %elem7, align 8
  %1 = call i32 @printf(ptr nonnull @conststr, ptr nonnull %__c2rob_printf_pack_0, i32 zeroext 10, i32 zeroext 3)
  store i64 1, ptr %__c2rob_printf_pack_1, align 8
  store i64 1, ptr %elem12, align 8
  store i64 3, ptr %elem13, align 8
  %2 = call i32 @printf(ptr nonnull @conststr.1, ptr nonnull %__c2rob_printf_pack_1, i32 zeroext 8, i32 zeroext 3)
  %elem26 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 8
  %elem27 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 16
  store i64 1, ptr %__c2rob_printf_pack_2, align 8
  store i64 1, ptr %elem26, align 8
  store i64 0, ptr %elem27, align 8
  %3 = call i32 @printf(ptr nonnull @conststr.2, ptr nonnull %__c2rob_printf_pack_2, i32 zeroext 8, i32 zeroext 3)
  store i64 1, ptr %__c2rob_printf_pack_2, align 8
  store i64 1, ptr %elem26, align 8
  store i64 1, ptr %elem27, align 8
  %4 = call i32 @printf(ptr nonnull @conststr.2, ptr nonnull %__c2rob_printf_pack_2, i32 zeroext 8, i32 zeroext 3)
  store i64 1, ptr %__c2rob_printf_pack_3, align 8
  %elem46 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_3, i32 8
  store i64 1, ptr %elem46, align 8
  %elem47 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_3, i32 16
  store i64 1, ptr %elem47, align 8
  %5 = call i32 @printf(ptr nonnull @conststr.3, ptr nonnull %__c2rob_printf_pack_3, i32 zeroext 8, i32 zeroext 3)
  %checks.i = load i32, ptr @checks, align 4
  %binop.i87 = add i32 %checks.i, 2
  store i32 %binop.i87, ptr @checks, align 4
  store i64 2, ptr %__c2rob_printf_pack_4, align 8
  %elem81 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_4, i32 8
  store i64 1, ptr %elem81, align 8
  %elem82 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_4, i32 16
  store i64 0, ptr %elem82, align 8
  %elem83 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_4, i32 24
  store i64 1, ptr %elem83, align 8
  %elem84 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_4, i32 32
  store i64 1, ptr %elem84, align 8
  %6 = call i32 @printf(ptr nonnull @conststr.4, ptr nonnull %__c2rob_printf_pack_4, i32 zeroext 14, i32 zeroext 5)
  %checks = load i32, ptr @checks, align 4
  ret i32 %checks
}

attributes #0 = { "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }
attributes #1 = { mustprogress nofree norecurse nosync nounwind willreturn memory(readwrite, argmem: none, inaccessiblemem: none) "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }

!llvm.module.flags = !{!0}

!0 = !{i32 7, !"frame-pointer", i32 2}
