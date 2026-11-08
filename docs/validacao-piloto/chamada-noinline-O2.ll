; ModuleID = 'test/unit/out-pilot-integration/pilot_noinline_definition.validation.rob'
source_filename = "test/unit/out-pilot-integration/pilot_noinline_definition.validation.rob"
target datalayout = "e-m:e-p:32:32-Fi8-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "thumbv7m-none-eabi"

; Function Attrs: mustprogress nofree noinline norecurse nosync nounwind willreturn memory(none)
define i32 @inc(i32 %n) local_unnamed_addr #0 {
body:
  %binop = add i32 %n, 1
  ret i32 %binop
}

; Function Attrs: mustprogress nofree noinline norecurse nosync nounwind willreturn memory(none)
define i32 @pilot_definition(i32 %n) local_unnamed_addr #0 {
body:
  %0 = tail call i32 @inc(i32 %n)
  %binop = add i32 %0, 2
  ret i32 %binop
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(none)
define noundef i32 @main() local_unnamed_addr #1 {
body:
  ret i32 0
}

attributes #0 = { mustprogress nofree noinline norecurse nosync nounwind willreturn memory(none) "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }
attributes #1 = { mustprogress nofree norecurse nosync nounwind willreturn memory(none) "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }

!llvm.module.flags = !{!0}

!0 = !{i32 7, !"frame-pointer", i32 2}
