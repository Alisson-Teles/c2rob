; ModuleID = 'printf_packets.validation.rob'
source_filename = "printf_packets.validation.rob"
target datalayout = "e-m:e-p:32:32-Fi8-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "thumbv7m-none-eabi"

@chamadas = local_unnamed_addr global i32 0
@conststr = private unnamed_addr constant [0 x i8] zeroinitializer
@conststr.1 = private unnamed_addr constant [6 x i8] c"Ready\0A"
@conststr.2 = private unnamed_addr constant [35 x i8] c"%d %u %lld %llu %.2f %.2f %d %s %%\0A"
@conststr.3 = private unnamed_addr constant [7 x i8] c"a%d %s\0A"

declare i32 @printf(ptr, ptr, i32 zeroext, i32 zeroext) local_unnamed_addr #0

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(readwrite, argmem: none, inaccessiblemem: none)
define i32 @next(i32 %n) local_unnamed_addr #1 {
body:
  %chamadas = load i32, ptr @chamadas, align 4
  %binop = add i32 %chamadas, 1
  store i32 %binop, ptr @chamadas, align 4
  %binop3 = shl i32 %n, 1
  ret i32 %binop3
}

define void @show(i8 %n, i32 zeroext %u, i64 %l, i64 zeroext %ul, float %x, double %y) local_unnamed_addr #0 {
body:
  %__c2rob_printf_pack_0 = alloca [1 x i64], align 8
  %__c2rob_printf_pack_1 = alloca [1 x i64], align 8
  %__c2rob_printf_pack_2 = alloca [19 x i64], align 8
  %__c2rob_printf_pack_3 = alloca [7 x i64], align 8
  store i64 0, ptr %__c2rob_printf_pack_0, align 8
  %0 = call i32 @printf(ptr nonnull @conststr, ptr nonnull %__c2rob_printf_pack_0, i32 zeroext 0, i32 zeroext 1)
  store i64 0, ptr %__c2rob_printf_pack_1, align 8
  %1 = call i32 @printf(ptr nonnull @conststr.1, ptr nonnull %__c2rob_printf_pack_1, i32 zeroext 6, i32 zeroext 1)
  %fpext = fpext float %x to double
  %chamadas.i = load i32, ptr @chamadas, align 4
  %binop.i = add i32 %chamadas.i, 1
  store i32 %binop.i, ptr @chamadas, align 4
  %sext16 = sext i8 %n to i64
  %zext = zext i32 %u to i64
  store i64 8, ptr %__c2rob_printf_pack_2, align 8
  %elem25 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 8
  store i64 1, ptr %elem25, align 8
  %elem26 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 16
  store i64 %sext16, ptr %elem26, align 8
  %elem27 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 24
  store i64 2, ptr %elem27, align 8
  %elem28 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 32
  store i64 %zext, ptr %elem28, align 8
  %elem29 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 40
  store i64 3, ptr %elem29, align 8
  %elem30 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 48
  store i64 %l, ptr %elem30, align 8
  %elem31 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 56
  store i64 4, ptr %elem31, align 8
  %elem32 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 64
  store i64 %ul, ptr %elem32, align 8
  %elem33 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 72
  store i64 5, ptr %elem33, align 8
  %elem34 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 80
  store double %fpext, ptr %elem34, align 8
  %elem35 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 88
  store i64 5, ptr %elem35, align 8
  %elem36 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 96
  store double %y, ptr %elem36, align 8
  %elem37 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 104
  store i64 1, ptr %elem37, align 8
  %elem38 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 112
  store i64 6, ptr %elem38, align 8
  %elem39 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 120
  store i64 6, ptr %elem39, align 8
  %elem40 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 128
  store i64 2, ptr %elem40, align 8
  %elem41 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 136
  store i64 111, ptr %elem41, align 8
  %elem42 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_2, i32 144
  store i64 107, ptr %elem42, align 8
  %2 = call i32 @printf(ptr nonnull @conststr.2, ptr nonnull %__c2rob_printf_pack_2, i32 zeroext 35, i32 zeroext 19)
  store i64 2, ptr %__c2rob_printf_pack_3, align 8
  %elem47 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_3, i32 8
  store i64 1, ptr %elem47, align 8
  %elem48 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_3, i32 16
  store i64 7, ptr %elem48, align 8
  %elem49 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_3, i32 24
  store i64 6, ptr %elem49, align 8
  %elem50 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_3, i32 32
  store i64 2, ptr %elem50, align 8
  %elem51 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_3, i32 40
  store i64 65, ptr %elem51, align 8
  %elem52 = getelementptr inbounds i8, ptr %__c2rob_printf_pack_3, i32 48
  store i64 66, ptr %elem52, align 8
  %3 = call i32 @printf(ptr nonnull @conststr.3, ptr nonnull %__c2rob_printf_pack_3, i32 zeroext 7, i32 zeroext 7)
  ret void
}

define i32 @main() local_unnamed_addr #0 {
body:
  tail call void @show(i8 -2, i32 zeroext -1, i64 -9007199254740993, i64 zeroext -1, float 1.000000e+00, double 2.000000e+00)
  %chamadas = load i32, ptr @chamadas, align 4
  ret i32 %chamadas
}

attributes #0 = { "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }
attributes #1 = { mustprogress nofree norecurse nosync nounwind willreturn memory(readwrite, argmem: none, inaccessiblemem: none) "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }

!llvm.module.flags = !{!0}

!0 = !{i32 7, !"frame-pointer", i32 2}
