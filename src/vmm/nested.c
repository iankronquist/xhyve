#include <xhyve/vmm/intel/vmcs.h>
#include <xhyve/vmm/nested.h>
#include <xhyve/vmm/vmm_api.h>

int
nested_vmexit_vmx(struct vm_exit *vme, int *pvcpu) {
	switch(vme->u.vmx.exit_reason) {
		case EXIT_REASON_VMXON:
			return xh_vm_emulate_l1_vmxon(*pvcpu);
		case EXIT_REASON_VMXOFF:
			return xh_vm_emulate_l1_vmxoff(*pvcpu);
		default:
			return (-1);
	}
}
